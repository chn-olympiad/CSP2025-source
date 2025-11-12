#include<bits/stdc++.h>
using namespace std;
int t,ans,n,a[100002],b[100002],c[100002],qz[100005];
bool flag1,flag2;
void dfs(int p,int x,int y,int z,int s){
	if(x>n/2||y>n/2||z>n/2||s+qz[p]<=ans)return ;
	if(p>n){
		ans=max(ans,s);
		return ;
	}
	dfs(p+1,x+1,y,z,s+a[p]);
	dfs(p+1,x,y+1,z,s+b[p]);
	dfs(p+1,x,y,z+1,s+c[p]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			qz[i]=max(a[i],max(b[i],c[i]));
			if(b[i]!=0)flag1=0;
			if(c[i]!=0)flag2=0;
		}
		if(flag2){
			if(flag1){
				sort(a+1,a+n+1);
				for(int i=n;i>n/2;i--)ans+=a[i];
				printf("%d\n",ans);
				continue;
			}
		}
		for(int i=n-1;i>=1;i--)qz[i]+=qz[i+1];
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
