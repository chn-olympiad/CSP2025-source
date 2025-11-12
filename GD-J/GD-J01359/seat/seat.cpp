#include<bits/stdc++.h>
using namespace std;
struct node{
	int i,p;
}a[120];
bool cmp(node a,node b)
{
	return a.p>b.p;
}
int n,m,i,j;
int fun(int l)
{
	int x;
	if(l%n==0)
	{
		x=l/n;
	}
	else
	{
		x=l/n+1;
	}
	return x;
}
int hang(int m,int l)
{
	int x=m-1;
	x*=n;
	l-=x;
	if(m%2==0)
	{
		return n-l+1;
	}
	else
	{
		return l;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i].p;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i].i==1)
		{
			int tmp=fun(i);
			cout<<tmp<<" "<<hang(tmp,i);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
