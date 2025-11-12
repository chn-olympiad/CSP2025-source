#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> a;
ll cnt;
void dfs(ll k, ll sum, ll st,ll most,ll nmax){
    ll cnt = 0;
    if(k >= most) {
        //cout<<cnt;
        if(sum > 2*nmax){
            cnt++;
        }
        return ;
    }
    for(int i =st;i <= n;i++){
        if(a[i] < nmax){
            dfs(k+1,sum+a[i],i+1,most,nmax);
        }
        else{
            dfs(k+1,sum+a[i],i+1,most,a[i]);
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++){
        ll tmp;cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());

    if(n == 3){
        if(a[1] + a[2] < a[3]){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    if(n > 3){
        cnt = 10;
        dfs(0,0,1,5,-1);

    }
    cout<<cnt;

    return 0;
}

