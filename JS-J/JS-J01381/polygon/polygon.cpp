#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
bool vis[5005];
void f(int x,int s,int maxn,int t){
    //if(x>n) return ;
    //cout<<x<<"    "<<s<<"    "<<maxn<<"    "<<t<< "     "<<ans<<endl<<endl;
    for(int i=x;i<=n;++i){
        if(vis[i]) continue;
        maxn=max(maxn,a[i]);
        s+=a[i];
        if(s>maxn*2&&t>=3){
            //cout<<t<<endl;
            ans++;
            ans%=998244353;
        }
        vis[i]=1;
        f(i+1,s,maxn,t+1);
        vis[i]=0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        memset(vis,0,sizeof(vis));
        f(i,0,-1,0);
    }
    cout<<ans;
    return 0;
}
//give me some points please!
