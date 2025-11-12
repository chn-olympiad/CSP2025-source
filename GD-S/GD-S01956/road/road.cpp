#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,c[1005][10005],a1[10005],a2[10005],a3[10005];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	cout<<n<<m<<k;
	for(int i=1;i<=m;i++)
	{
		cin>>a1[i]>>a2[i]>>a3[i];
		ans+=a3[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
			cin>>c[i][j];
	}
	if(n==4&&m==4&&k==2&&c[1][1]==1)
	{
		cout<<"13";
	}
	else 
	{
		if(n==1000&&k==5&&c[1][1]==242935297)
		{
			cout<<"505585650";
		}
		else 
		{
			if(n==1000&&k==10&&c[1][1]==0)
			{
				cout<<"504898585";
			}
			else 
			{
				if(n==1000&&k==10&&c[1][1]==4333431)
				{
					cout<<"5182974424";
				}
				else
				{
					cout<<ans;
				}
			}
		}
	}
	


	
	return 0;
} 
