//seat√ 
#include<bits/stdc++.h>
using namespace std;
int a[105],sum=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,hang,lie;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[0])
			sum++;
	}
	t=a[0];
	int shang=sum/n;
	if(sum%n==0)//除的尽 1||最后一行 
	{
		lie=shang;
		if(shang%2==0)//商偶数 
			hang=1;
		if(shang%2!=0)
			hang=n;
	}
	else if(sum%n!=0)//除不尽 
	{
		lie=shang+1;
		if(shang%2==0)
		{
			hang=sum%n;
		 } 
		if(shang%2!=0)
		{
			hang=n-(sum%n)+1;
		}
	}
	cout<<lie<<' '<<hang;
	return 0;
 } 