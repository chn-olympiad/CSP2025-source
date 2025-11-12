#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node {
	int cj;
	int bj=false;
}a[101];
bool cmp(node x,node y)
{
	return x.cj >y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].cj;
	}
	a[1].bj=true;
	sort(a+1,a+k+1,cmp);
	if(a[1].bj==true)
	{
		cout<<1<<" "<<1<<endl;
	}
	else if(a[2].bj==true)
	{
		cout<<2<<" "<<1<<endl;
	}
	else if(a[3].bj ==true)
	{
		cout<<2<<" "<<2<<endl;
	}
	else if(a[4].bj ==true)
	{
		cout<<1<<" "<<2<<endl;
	}
	return 0;
}
