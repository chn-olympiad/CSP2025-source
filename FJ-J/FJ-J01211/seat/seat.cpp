#include<bits/stdc++.h>
using namespace std;
struct node{
	int fs;
	int xb;
}a[1000];
bool cmp(node x,node y)
{
	return x.fs>y.fs;
}
int main(){
	int n,m,z;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].fs;
		a[i].xb=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].xb==1)
		{
			z=i;
			break;
		}
	}
	int l;
	if(z%n==0) l=z/n;
	else l=z/n+1;
	cout<<l<<" ";
	int h;
	if(l%2==0) h=n-z%n+1;
	else 
	{
		if(z%n==0) h=n;
		else h=z%n;
	}
	cout<<h;
	return 0;
}
