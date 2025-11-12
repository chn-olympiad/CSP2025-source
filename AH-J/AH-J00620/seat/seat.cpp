#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) s=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int v;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s) 
		{
			v=i;
			break;
		}
	}
	int x=v/n;
	if(n*x!=v) x++;
	if(x%2==1) 
	{
		int w=(x-1)*n;
		v-=w;
		cout<<x<<' '<<v<<endl;
		return 0;
	}
	else
	{
		int w=(x-1)*n;
		v-=w;
		v=n+1-v;
		cout<<x<<' '<<v<<endl;
		return 0;
	}
	return 0;
}
