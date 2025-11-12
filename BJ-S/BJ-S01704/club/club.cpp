#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t[4][N];
int ans=-N;
int n;
void dfs(int x,int a,int b,int c,int d,int e,int f){
    if(x==0){
        if(ans<a+b+c)   ans=a+b+c;
        else
        return;
    }
    if(d<n/2)  dfs(x-1,a+t[x][1],b,c,d+1,e,f);
    if(e<n/2)  dfs(x-1,a,b+t[x][2],c,d,e+1,f);
    if(f<n/2)  dfs(x-1,a,b,c+t[x][3],d,e,f+1);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--){
        cin>>n;int b=0,c=0;
        for(int i=1;i<=n;i++){
            cin>>t[1][i]>>t[2][i]>>t[3][i];
            b+=t[2][i];c+=t[3][i];
        }
        ans=0;
        if(n<=10){
            dfs(n,0,0,0,0,0,0);
            cout<<ans<<'\n';
            ans=-N;
            memset(t,0,sizeof(int));
        }else{
            if(b==0){
                sort(t[1]+1,t[1]+n+1);
                ans=0;
                for(int i=1;i<=n/2;i++){
                    ans+=t[1][i];
                }
                cout<<ans<<'\n';
            }else if(c==0){
                for(int i=1;i<=n;i++){
                    ans+=max(t[1][i],t[2][i]);
                }
                cout<<ans<<'\n';
            }else{
                for(int i=1;i<=n;i++){
                    ans+=max(t[1][i],t[2][i]);
                    ans+=max(t[1][i],t[3][i]);
                    ans+=max(t[2][i],t[3][i]);
                }
                cout<<ans*10/27<<'\n';
            }
        }

    }
    return 0;
}
