#include<bits/stdc++.h>
using namespace std;
int a[1005];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,k=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==k)
		{
			int j=i;
			if(j%n==0)j/=n;
			else j=j/n+1;
			if(j%2==1)i=i-(j-1)*n;
			else i=j*n-i+1;
			cout<<j<<' '<<i;
			return 0;
		}
	return 0;
}

