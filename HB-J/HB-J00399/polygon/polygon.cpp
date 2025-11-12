#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int vis[5005];
int b[5005];
long long jc[25];
long long ans=0;long long sans;
void dfs(int x,int m,int sum,int maxa){
    if(x>m){
        if(sum>maxa*2){
            ans++;
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            b[x]=a[i];
            dfs(x+1,m,sum+a[i],max(maxa,a[i]));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    /*jc[0]=1;*/
    jc[1]=1;
    for(int i=2;i<=15;i++){
        jc[i]=jc[i-1]*i;
        //cout<<jc[i]<<endl;
    }
    for(int i=3;i<=n;i++){
            ans=0;
        dfs(1,i,0,0);
        long long t=1;
        long long fw=1;
        t=jc[n]/max(fw,jc[n-i]);
        //cout<<ans<<" ";
        if(ans%t!=0)ans+=t;
        ans/=t;
        sans+=ans;
        //cout<<t<< " "<<ans<<" "<<sans<<endl;
    }
    cout<<sans<<endl;
    return 0;
}
