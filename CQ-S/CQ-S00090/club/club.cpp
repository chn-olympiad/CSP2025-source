#include<bits/stdc++.h>
using namespace std;
int a[110000][4],n,ans=0,lim,s[1110],sk[1100];
void dfs(int k,int total,int x,int y,int z)
{
	if(k==n+1)
	{
		ans=max(ans,total);
		if(total==ans)
		{
			for(int i=1;i<=n;i++)
			{
				sk[i]=s[i];
			}
		}
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		s[k]=i;
		int g=x+(i==1),h=y+(i==2),j=z+(i==3);
		if(g<=lim && h<=lim && j<=lim) dfs(k+1,total+a[k][i],x+(i==1),y+(i==2),z+(i==3));
	}
}
int main(){
	
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&n);
	lim=n/2;
	for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
	dfs(1,0,0,0,0);
	for(int i=1;i<=n;i++)
	{
		cout<<sk[i]<<'\n';
	}
	printf("%d",ans);
	
	
	
	return 0;
}
