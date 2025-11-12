#include<bits/stdc++.h>
using namespace std;
int T,n,a1[50050],a2[50050],a3[50040],ans,num1,num2,num3,maxx=-1;
int amax[500][500][500];
void dfs(int a)
{
	if(a==n+1)
	{
		maxx=max(maxx,ans);
		return;
	}
	if(a!=1&&amax[num1][num2][num3]>ans)
	{
		return;
	}
	else
	{
		amax[num1][num2][num3]=ans;
	}
	if(num1<n/2)
	{
		ans+=a1[a];
		num1++;
		dfs(a+1);
		ans-=a1[a];
		num1--;
	}
	if(num2<n/2)
	{
		ans+=a2[a];
		num2++;
		dfs(a+1);
		ans-=a2[a];
		num2--;
	}
	if(num3<n/2)
	{
		ans+=a3[a];
		num3++;
		dfs(a+1);
		ans-=a3[a];
		num3--;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>n;
		maxx=0;
		ans=0;
		num1=0,num2=0,num3=0;
		for(int i=0;i<=n/2;i++)
			for(int ii=0;ii<=n/2;ii++)
				for(int iii=0;iii<=n/2;iii++)
					amax[i][ii][iii]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		}
		dfs(1);
		cout<<maxx<<endl;
	}
	return 0;
}
