#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,a[N][3],b[N],n,s;
inline void dfs(int dep,int x,int y,int z,int sum){
	if(dep>n){
		s=max(s,sum);
		return ;
	}
	if(x>n/2||y>n/2||z>n/2)
		return ;
	dfs(dep+1,x+1,y,z,sum+a[dep+1][1]);
	dfs(dep+1,x,y+1,z,sum+a[dep+1][2]);
	dfs(dep+1,x,y,z+1,sum+a[dep+1][3]);
}
inline void dfs2(int dep,int x,int y,int sum){
	if(dep>n){
		s=max(s,sum);
		return ;
	}
	if(x>n/2||y>n/2)
		return ;
	dfs2(dep+1,x+1,y,sum+a[dep+1][1]);
	dfs2(dep+1,x,y+1,sum+a[dep+1][2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		s=0;
		bool flag1=false,flag2=false;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=3; j++){
				scanf("%d",&a[i][j]);
				if(a[i][2]!=0||a[i][3]!=0) flag1=true;
				if(a[i][3]!=0) flag2=true;
			}
		if(!flag1){
			for(int i=1; i<=n; i++) b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n/2+1; i<=n; i++)
				s+=b[i];
			printf("%d\n",s);
			continue;	
		}
		if(!flag2){
			dfs2(0,0,0,0);
			printf("%d\n",s);
			continue;
		}
		dfs(0,0,0,0,0);
		printf("%d\n",s);
	}
	return 0;
}
