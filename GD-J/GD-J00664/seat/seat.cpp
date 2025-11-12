#include<bits/stdc++.h>
using namespace std;
int f[105][2];
int a[105];
int h(int n,int k)
{
	while(n%k!=0)n++;
	return n+1; 
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		if(i%n==0)
		{
			f[i][0]=i/n;
			if(f[i][0]%2==1)f[i][1]=n;
			else f[i][1]=1;
		}
		else
		{
			f[i][0]=i/n+1;
			int k=i/n;
			if(k%2==0)f[i][1]=i%n;
			else f[i][1]=h(i,2*n)-i;
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int k=a[1],l=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			l=i;
			break;
		}
	}
	cout<<f[l][0]<<" "<<f[l][1];
}
