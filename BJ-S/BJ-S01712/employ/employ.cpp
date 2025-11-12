#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,m;
string s;
pair<ll,ll> c[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i].second;
        c[i].first=i;
    }
    ll allans=0;
    do{
        ll time1=0,all=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'&&time1<c[i].second){
                all++;
            }else{
                time1++;
            }
        }
        if(all>=m){
            allans++;
            allans%=MOD;
        }
    }while(next_permutation(c+1,c+n+1));
    cout<<allans%MOD<<endl;
    return 0;
}
