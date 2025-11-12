#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200010][2],b[200010][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	//for(int i=1;i<=q;i++)
	//{
	//	cout<<0<<endl;
	//}
	int sum=0;
	for(int i=1;i<=q;i++)
	{
		
		if(a[i][0].size()!=a[i][1].size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<a[i][0].size()-b[j][0].size();k++)
			{
				int f=0;
				for(int x=0;x<k;x++)
				{
					if(a[i][0][x]!=a[i][1][x])
					{
						f=1;
						break;
					}
				}
				if(f==1) continue;
				for(int x=k;x<b[j][0].size()+k;x++)
				{
					if(a[i][0][x]!=b[j][0][x]||a[i][1][x]!=b[j][1][x])
					{
						f=1;
						break;
					}
				}
				if(f==1) continue;
				for(int x=b[j][0].size()+k;x<a[i][0].size();x++)
				{
					if(a[i][0][x]!=a[i][1][x])
					{
						f=1;
						break;
					}
				}
				if(f==0)
				{
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
