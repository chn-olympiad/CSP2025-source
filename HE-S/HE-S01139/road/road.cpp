#include<bits/stdc++.h>
using namespace std;
long long r[1005][1005],ans[1005]={},ch[1005][1005]={};
bool s[1005][1005]={},p[1005][1005];
int n,m,k;
int mapx(int be,int fi){
	if(r[be][fi]==-1)
	{
		return INT_MAX;
	}
	int an=r[be][fi];
	for(int i=1;i<=m;i++)
	{
		if(r[be][i]==-1||p[be][i])
		{
			continue;
		}
		p[be][i]=1;
//		cout<<an<<" ";
		an=min(an,mapx(i,fi));
		p[be][i]=0;
//		cout<<endl;
	}
	return an;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=n;i++)
	{
		ans[i]=INT_MAX;
		for(int j=0;j<=m;j++)
		{
			ch[i][j]=-1;
			r[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		r[a][b]=r[b][a]=c;
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<r[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(int i=1;i<=k;i++)
	{
		int temp;
		cin>>temp;
		for(int j=1;j<1+n;j++)
		{
			ch[i][j]=temp;
			int temp1;
			cin>>temp1;
			if(r[i][j]==-1)
			{
				r[i][j]=temp1;
				s[i][j]=true;
			}
			else
			{
				if(temp+temp1<r[i][j])
				{
					r[i][j]=temp1;
					s[i][j]=true;
				}
			}
			if(j==i)
			{
				r[i][j]=temp1;
				s[i][j]=true;
			}
		}
	}
	int temp[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			temp[i][j]=r[i][j];
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<r[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<s[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<ch[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(r[i][j]!=-1)
			{
				ans[i]=mapx(1,j);
			}
		}
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<ans[i]<<" ";
//	}
	int ans1=0;
	for(int i=1;i<=n;i++)
	{
		ans1+=ans[i];//写不完了加一下得了 
	}
	cout<<ans1<<endl;
	return 0;
	return 0;
}
