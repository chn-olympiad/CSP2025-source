#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}a[100001];
int n,ans;
void dfs(int step,int tmp,int a1,int b1,int c1){
    if(step==n+1){
        ans=max(ans,tmp);
        return;
    }
    if(a1<n/2){
        dfs(step+1,tmp+a[step].a,a1+1,b1,c1);
    }
    if(b1<n/2){
        dfs(step+1,tmp+a[step].b,a1,b1+1,c1);
    }
    if(c1<n/2){
        dfs(step+1,tmp+a[step].c,a1,b1,c1+1);
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
        }
        dfs(1,0,0,0,0);
        printf("%d\n",ans);
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
