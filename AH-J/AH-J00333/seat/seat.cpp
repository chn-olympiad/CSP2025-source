#include<bits/stdc++.h>
using namespace std;
int n,m,g,ansl,ansh;
int a[12000];
bool cmp(int a,int b)
{
	return a>b;
}
int find(int x)
{
	int r=0,l=n*m-1;
	while(r<l)
	{
		int mid=(r+l)/2;
		if(a[mid]==x) return mid;
		if(a[mid]>x) r=mid+1;
		else if(a[mid]<x) l=mid-1;
	}
	return l;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	int ui=a[0];
	sort(a,a+n*m,cmp);
	g=find(ui)+1;
	ansl=g/n;
	if(ansl*n!=g) ansl++;
	if(ansl%2==0) ansh=m-(g%n)+1;
	else 
	{
		ansh=g%n;
		if(ansh==0) ansh=n;
	}
	printf("%d %d\n",ansl,ansh);
	return 0;
}
