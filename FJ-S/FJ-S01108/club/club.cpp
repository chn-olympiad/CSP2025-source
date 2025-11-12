#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N][5],ddd[N],dd[N];int n,m;int anss=0;
//a[i][3]now,
int inita()
{
	int a1=0,a2=0,a3=0;
	for(int i=1;i<=n;i++)
	{
		a[i][3]=max(a[i][0],max(a[i][1],a[i][2]));
		if(a[i][3]==a[i][0])a1++,a[i][4]=0;
		else if(a[i][3]==a[i][1])a2++,a[i][4]=1;
		else a3++,a[i][4]=2;
	}
	if(a1<=m&&a2<=m&&a3<=m)return 1;
	return 0;
}

int dfs(int i,int ans)
{
	if(i==n)return ans;
	
	for(int j=0;j<3;j++)
	{
		anss=max(anss,dfs(i+1,ans+a[i][j])) ;
	}
	return anss;
}
bool cnt(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		m=n/2;anss=0;
		int a2_=0,a3_=0,anses=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ddd[i]=a[i][0];dd[i]=a[i][1];
			if(a[i][1]==0)a2_++;
			if(a[i][2]==0)a3_++;
		}
		
		int ans=inita(),sum=0;
		if(ans==1)
		{
			for(int i=1;i<=n;i++)
			{
				sum+=a[i][3];
			}
			cout<<sum<<endl;
		}
		else
		{
			if(a2_==n&&a3_==n)
			{
				sort(ddd+1,ddd+n+1,cnt);
				for(int i=1;i<=n/2;i++)
				{
					anses+=ddd[i];
				}
				cout<<anses;
				return 0;
			}
			cout<<dfs(1,0)<<endl;
		}
	}
	return 0;	
} 
