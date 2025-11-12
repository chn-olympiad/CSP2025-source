#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3;
long long n,m,a[maxn],R,Rs,x,y;
int main(){
	freopen("seat.in","r",stdin);	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%lld",&a[i]);
	R=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1,j=n*m;i<j;i++,j--)
		swap(a[i],a[j]);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			Rs=i;
		}
	}
	if(Rs%n==0)
	{
		if(Rs/n%2==1) x=Rs/n,y=n;
		else x=Rs/n,y=1;
	}
	else
	{
		x=Rs/n+1;
		y=Rs-Rs/n*n;
		//cout<<Rs<<" ";
		if(x%2==0) y=n-y+1;
	}
	printf("%lld %lld",x,y);
	
	return 0;
}
/*
2 2
99 100 97 98



2 2
98 99 100 97
*/
