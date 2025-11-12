#include<bits/stdc++.h>

using namespace std;

int n,a[100005],b[100005],c[100005],ans;
int x,y,z;

bool tA=1;

inline void dfs(int k,int sum){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i){
		if(i==1&&x<n/2)++x,dfs(k+1,sum+a[k]),--x;
		if(i==2&&y<n/2)++y,dfs(k+1,sum+b[k]),--y;
		if(i==3&&z<n/2)++z,dfs(k+1,sum+c[k]),--z;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0,x=0,y=0,z=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(b[i]!=0||c[i]!=0) tA=0;
		}
		if(tA){
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;--i){
				ans+=a[i];
			}
			printf("%d\n",ans);
			continue;
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}

