#include<bits/stdc++.h>
using namespace std;
int sa[200001][4],n,t;
int ans=0,spa[200001];
int f[200001][4];
void dfs(int a,int b,int c,int sum,int cnt)
{
	if(a>n/2||b>n/2||c>n/2)return;
	//cerr<<a<<' '<<b<<' '<<c<<' '<<sum<<' '<<cnt<<endl; 
	if(a+b+c==n){
		ans=max(ans,sum);
		return;
	}
	dfs(a+1,b,c,sum+sa[cnt][1],cnt+1);
	dfs(a,b+1,c,sum+sa[cnt][2],cnt+1);
	dfs(a,b,c+1,sum+sa[cnt][3],cnt+1);
}
bool check(){
	for(int i=1;i<=n;i++)
	{
		if(sa[i][2]*sa[i][3]!=0)return false;
	} 
	return true;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&sa[i][1],&sa[i][2],&sa[i][3]);
		}
		if(check()){
			for(int i=1;i<=n;i++)spa[i]=sa[i][1];
			sort(spa+1,spa+n+1,greater<int>());
			int sum=0;
			for(int i=1;i<=n/2;i++)sum+=spa[i];
			printf("%d\n",sum);
			continue;
		}
		if(n>10){
			memset(f,0,sizeof f);
			for(int i=1;i<=n;i++)
			{
				f[i][1]=max(f[i-1][1]+sa[i][1],max(f[i-1][2]+sa[i][1],f[i-1][3]+sa[i][1]));
				f[i][2]=max(f[i-1][1]+sa[i][2],max(f[i-1][2]+sa[i][2],f[i-1][3]+sa[i][2]));
				f[i][3]=max(f[i-1][1]+sa[i][3],max(f[i-1][2]+sa[i][3],f[i-1][3]+sa[i][3]));
			}
			int ans=max(f[n][1],max(f[n][2],f[n][3]));
			printf("%d\n",ans);
			continue;
		}
		dfs(0,0,0,0,1);
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
