#include<bits/stdc++.h>
using namespace std;
int n,a[100005][3],ans=0;
void dfs(int sum,int x,int f1,int f2,int f3){
    if(x>n){
        ans=max(ans,sum);
        return;
    }
    if(f1<=n/2)dfs(sum+a[x][0],x+1,f1+1,f2,f3);
    if(f2<=n/2)dfs(sum+a[x][1],x+1,f1,f2+1,f3);
    if(f3<=n/2)dfs(sum+a[x][2],x+1,f1,f2,f3+1);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        ans=0;
        if(n<=100){
            dfs(0,1,1,1,1);
            cout<<ans<<endl;
        }else{
            int b[100005];
            for(int i=1;i<=n;i++){
                b[i]=a[i][0];
            }
            sort(b+1,b+n+1);
            for(int i=n;i>n/2;i--){
                ans+=b[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}