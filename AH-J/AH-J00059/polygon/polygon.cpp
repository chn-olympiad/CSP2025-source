#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[5007],b[5007],vis[5007];
void dfs(long long h,int i,int c,int c1){
    if(i==n&&c>c1)return;
    if(c==c1){
        for(int i=5006;i>=0;i--){
             if(vis[i]==1){
                if(h>a[i]*2){
                    cnt++;
                    cnt%=998244353;

                }return ;
             }
        }return;
    }
    dfs(h,i+1,c,c1);
    vis[i]=1;
    dfs(h+a[i],i+1,c,c1+1);
    vis[i]=0;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    //if(n==3){
    //    long long mx=0,h=0;
    //    for(int i=0;i<n;i++)mx=max(mx,a[i]),h+=a[i];
     //   if(mx*2>h)cout<<1;
    //    else cout<<0;
    //}else{
        sort(a,a+n);
        /*b[0]=a[0];
        for(int i=1;i<n;i++)b[i]=a[i]+b[i-1];
        for(int i=3;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                if(b[j+i-1]-b[j-1]>a[i+j-1]*2){
                    cnt++,cnt%=998244353;

                }
            }
        }cout<<cnt;*/
        for(int i=3;i<=n;i++){
            dfs(0,0,i,0);
        }
        cout<<cnt;
   // }

    return 0;

}//#Shang4Shan3Ruo6Shui4
