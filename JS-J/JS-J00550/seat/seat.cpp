#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,a,d,ans1,ans2;
vector<int> v;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>x;
        if(i==1)a=x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    d=v.end()-lower_bound(v.begin(),v.end(),a);
    if(d%n==0){
        ans1=d/n;
        if(ans1%2==1){
            ans2=n;
        }else{
            ans2=1;
        }
    }else{
        ans1=d/n+1;
        if(ans1%2==1){
            ans2=d%n;
        }else{
            ans2=n-d%n+1;
        }
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}