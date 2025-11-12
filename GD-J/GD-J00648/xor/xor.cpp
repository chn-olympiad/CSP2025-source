#include<bits/stdc++.h>
using namespace std;
//int sum[500002][500002];
int main()
{
//	try{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<vector<int> >sum(n+3,vector<int>(n+3));
	vector<int>a(n+3);
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		sum[i][i]=a[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			if(i>j)
			sum[i][j]=k+1;
			if(sum[i][j])continue;
			sum[i][j]=(sum[i][j-1]^a[j]);
		}
//	for(int i=1; i<=n; i++)
//	{
//		for(int j=1; j<=n; j++)
//			cout<<sum[i][j]<<' ';
//		cout<<'\n';
//	}
	int i=1,j=1,ans=0;
//	for(int j=1; j<=n; j++)
//	{
//		int i=syc;
//		while(sum[i][j]!=k&&i<=j)
//			i++;
//		if(sum[i][j]==k&&syc<=i&&syc<=j)
//		{
//			ans++;
//			syc=i+1;
//			j=i+1;
//		}
//	}
	while(j<=n)
	{
		int l=i;
		while(sum[l][j]!=k&&l<=j)
		l++;
		if(sum[l][j]==k)
		{
			ans++;
			i=j+1;
			j++;
		}
		else
		j++;
	}
	cout<<ans;
	// system("pause");
	return 0;
//	}
//	catch(...)
//	{
//		cout<<"error";
//	}
}
