#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,ans,q[5][100005],f[100005];
void dfs(int x,int h,int a,int b,int c){
    if(h+f[n]-f[x-1]<=ans)return;
    if(x==n+1){
        ans=max(ans,h);
        return;
    }
    if(a>0){
        dfs(x+1,h+q[x][1],a-1,b,c);
    }
    if(b>0){
        dfs(x+1,h+q[x][2],a,b-1,c);
    }
    if(c>0){
        dfs(x+1,h+q[x][3],a,b,c-1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=-1;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>q[i][j];
            }
            f[i]=f[i-1]+max(q[i][1],max(q[i][2],q[i][3]));
        }
        dfs(1,0,n/2,n/2,n/2);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
