#include <bits/stdc++.h>
using namespace std;
long long t,n,m,ans,p;
struct node{
	long long x,y,z;
}a[100001];
void dfs(int in,int n1,int n2,int n3,long long b){
    if(in==(n+1)){
        ans=max(ans,b);
        return ;
    }
    if(n1+1<=m) dfs(in+1,n1+1,n2,n3,b+a[in].x);
    if(n2+1<=m) dfs(in+1,n1,n2+1,n3,b+a[in].y);
    if(n3+1<=m) dfs(in+1,n1,n2,n3+1,b+a[in].z);
    return ;
}
bool cmp(node u,node v){
	return u.x>v.x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        m=n/2;
        p=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
            if(a[i].y!=0||a[i].z!=0) p=1;
        }
        ans=0;
        if(p==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
		}else dfs(1,0,0,0,0);
        printf("%lld\n",ans);
    }
}
