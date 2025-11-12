#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[1000][3];
string b[1000][3];
int sum;
void df(string x,string y)
{
	int w=x.size();
	for(int i=1;i<=n;i++)
	{
		if(x==a[i][1]&&y==a[i][2])
		{
			sum++;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i][1]>>b[i][2];
		df(b[i][1],b[i][2]);
		cout<<sum<<endl;
		sum=0;
	}
	
	return 0;
}
