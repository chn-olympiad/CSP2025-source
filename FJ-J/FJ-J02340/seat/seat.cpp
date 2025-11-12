#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mkp make_pair
#define ft first
#define sc second
pii a[10001];
pii p[101][101];
bool cmp(pii a,pii b)
{
	return a.ft>b.ft;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].ft,a[i].sc=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2)
			for(int j=1;j<=n;j++)
				p[j][i]=a[++cnt];
		else
			for(int j=n;j>=1;j--)
				p[j][i]=a[++cnt];
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(p[i][j].sc==1)
				cout<<j<<" "<<i,exit(0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
