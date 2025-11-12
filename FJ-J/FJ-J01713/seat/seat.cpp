#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data,rank,index;
}a[10000];
bool cmp1(node a,node b)
{
	return a.data>b.data;
}
bool cmp2(node a,node b)
{
	return a.index<b.index;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].data;
		a[i].index=i;
	}
	sort(a+1,a+1+(m*n),cmp1);
	for(int i=1;i<=n*m;i++)
	{
		a[i].rank=i;
	}
	sort(a+1,a+1+(m*n),cmp2);
	s=a[1].rank;
	cout<<int(ceil(a[1].rank*1.0/n))<<' ';
	if(int(ceil(s*1.0/n))%2==0)
	{
		if(s%n==0) cout<<1;
		else cout<<n-(s%n)+1;
	}
	else
	{
		if(s%n==0) cout<<n;
		else cout<<s%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

