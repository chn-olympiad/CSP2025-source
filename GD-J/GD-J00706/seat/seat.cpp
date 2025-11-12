#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[10005];
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int z=a[1];
	int k;
	sort(1+a,1+n*m+a);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==z)
			k=i;
	}
	k=n*m-k+1;
	int mm,nn;
	if(k%n==0)
	{
		mm=k/n;
		if(mm%2==0)
			nn=1;
		else
			nn=n;
	}
	else
	{
		mm=k/n+1;
		if(mm%2==0)
			nn=n-(k%n)+1;
		else
			nn=k%n;
	}
	
	cout<<mm<<' '<<nn;
	return 0;
}
