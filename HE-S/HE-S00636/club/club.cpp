#include<iostream>
#include<cstdio>
using namespace std;
int t,n,man[100005][3],ans,p[3],mp;
void DFS(int num,long long sum)
{
	if(num==n+1&&ans<sum)
	{
		ans=sum;
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(p[i]+1<=mp)
		{
			p[i]++;
			DFS(num+1,sum+man[num][i]);
			p[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	froopen("club.out","w",stdout);
	
	cin>>t;
	for(int ceshi=0;ceshi<t;ceshi++)
	{
		ans=0,p[0]=0,p[1]=0,p[2]=0;
		cin>>n;
		mp=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>man[i][j];
			}
		}
		DFS(1,0);
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
