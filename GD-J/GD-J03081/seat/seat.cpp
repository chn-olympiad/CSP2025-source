#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[205];
	memset(a,0,sizeof(a));
	int x = 0;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x = a[1];
	sort(a + 1, a + n*m+1,cmp);
	int afa,beta;
	afa = 1,beta = 1;
	int way = 1;
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i] == x)
		{
			cout<<afa<<" "<<beta<<endl;
			return 0;
		}
		beta+=way;
		if(beta == n+1)
		{
			afa++;
			beta = n;
			way = -1;
		}
		if(beta == 0)
		{
			afa ++;
			beta = 1;
			way = 1;
		}
	}
	return 0;
} 
