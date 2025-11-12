#include<bits/stdc++.h>
using namespace std;
int n,k;
struct l
{
	int x,y;
};
bool ff(l a,l b)
{
	return a.y<b.y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int b[n][n];
	for(int i=0;i<n;i++)
	{
		b[i][i]=a[i];
		for(int j=i+1;j<n;j++)
		{
			b[i][j]=b[0][j-1]^a[j];
		}
	}
	int c=0;
	l sth[250000];
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(b[i][j]==k)
			{
				sth[c++].x=i;
				sth[c].y=j;
			}
		}
	}
	sort(sth,sth+250000,ff);
	int s=999999,cnt=0;
	for(int i=0;i<c;c++)
	{
		if(sth[i].x>s)
		{
			cnt++;
			s=sth[i].y;
		}
	}
	cout<<cnt;
	return 0;
}
