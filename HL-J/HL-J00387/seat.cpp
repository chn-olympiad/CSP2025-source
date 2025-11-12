#include <bits/stdc++.h>
#include <cstring>
using namespace std;

bool cmp(int a,int b)
{
	if(a!=b)
	{
		return a>b;
	}
}

int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	int m,n,a[101],R,in,c,r;
	cin>>m>>n;
	int k=m*n;
	for (int i=0;i<k;++i)
	{
		cin>>in;
		a[i]=in;
		if (i=0）  R=in;
	}
	
	sort(a+1,a+k+1,cmp);
	
	int j=0;
	while (a[j]=R)
	{
		j++;
	}
	r=j%m+1;
	c=((j-r)/m)+2;
	cout<<c<<" "<<r;
	return 0;
} 

