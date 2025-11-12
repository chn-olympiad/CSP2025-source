#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
struct Node{
    int a,b,c;
}a_[100010];
bool cmp(Node x,Node y){
    return max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c));
}
void DFS_(int x,int s1,int s2,int s3,int s){
    if(x>n){
        ans=max(ans,s);
        return;
    }
    if(s1<n/2)DFS_(x+1,s1+1,s2,s3,s+a_[x].a);
    if(s2<n/2)DFS_(x+1,s1,s2+1,s3,s+a_[x].b);
    if(s3<n/2)DFS_(x+1,s1,s2,s3+1,s+a_[x].c);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a_[i].a,&a_[i].b,&a_[i].c);
        if(n<=200)DFS_(1,0,0,0,0);
        else{
            sort(a_+1,a_+n+1,cmp);
            for(int i=1;i<=n/2;i++)ans+=max(a_[i].a,max(a_[i].b,a_[i].c));
        }
        printf("%d\n",ans);
    }
    return 0;
}
