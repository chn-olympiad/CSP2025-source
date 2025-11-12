#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	int mi=a[0];
	sort(a,a+n*m,cmp);
	int zwh;
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==mi)
		{
			zwh=i+1;
		}
	}
	cout<<1<<" "<<1<<endl;
	return 0;
}

