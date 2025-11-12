#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int a[200];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	int r;
	for(int i=1;i<=nm;i++)
	{
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++)
	{
		if(a[i]==r)
		{
			int mm,nn;
			if(i/n*n==i) mm=i/n;
			else mm=i/n+1;
			if(mm%2==0)
			{
				if(i%n==0) nn=1;
				else nn=n-i%n+1;
			}
			else
			{
				if(i%n==0) nn=n;
				else nn=i%n;
			}
			cout<<mm<<" "<<nn;
			break;
		}
	}
	return 0;
}
