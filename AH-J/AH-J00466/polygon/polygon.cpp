#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans;
bool b[5001];
inline void dfs(long long i,long long he,long long ma,long long ed){
    if(i==n+1&&ed>=3&&he!=0&&ma!=0&&ma*2<he){++ans;ans%=998244353ll;return;}
    if(i==n+1)return;
    //for(long long i=1;i<=n;++i){
        //if(!b[i]){
           // b[i]=true;
            //he+=a[i];
            //long long temp=ma;
           // ma=max(ma,a[i]);
           // dfs(he,ma);
         //   ma=temp;
       //     he-=a[i];
     //       b[i]=false;
   //     }
 //   }
    dfs(i+1,he,ma,ed);
    dfs(i+1,he+a[i],max(ma,a[i]),ed+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;++i){
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
