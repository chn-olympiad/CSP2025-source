#include<bits/stdc++.h>
using namespace std;
struct people{
    int a,b,c;
}a[int(1e5+10)];
int n;
long long ans=-1;//不开long long 见祖宗
void dfs(int x,int a1,int b,int c,long long sum){//选到第X人了，选A的人数，选B的人数，选C的人数，总满意度
    if(x==n+1){
        ans=max(ans,sum);
        return ;
    }
    if(a1<n/2)dfs(x+1,a1+1,b,c,sum+a[x].a);
    if(b<n/2)dfs(x+1,a1,b+1,c,sum+a[x].b);
    if(c<n/2)dfs(x+1,a1,b,c+1,sum+a[x].c);
}
void man(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c;
    }
    dfs(1,0,0,0,0);
    cout<<ans<<endl;
    ans=-1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)man();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
