#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int a;
    int b;
    int c;
}abc[100005];
int n;
int ans;
void dfs(int i,int cnt,int a,int b,int c){
    if(i>n){
        ans=max(ans,cnt);
        return;
    }
    if((n/2)>a){
        dfs(i+1,cnt+abc[i].a,a+1,b,c);
    }
    if((n/2)>b){
        dfs(i+1,cnt+abc[i].b,a,b+1,c);
    }
    if((n/2)>c){
        dfs(i+1,cnt+abc[i].c,a,b,c+1);
    }
    return ;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>abc[i].a>>abc[i].b>>abc[i].c;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
