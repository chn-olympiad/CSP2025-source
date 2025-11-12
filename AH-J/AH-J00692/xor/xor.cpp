#include <bits/stdc++.h>
using namespace std;
int a[500005];
int n,k;
bool pd1=true,pd2=true;
int c=0;
struct node{
	int st,en;
}t[500005];
bool cmp(node x,node y)
{
	return x.en<y.en;
}
int tmp;
int f=0;
void solve()
{
	for(int i=1;i<=n;i++)
	{
		int xo=0;
		for(int j=i;j<=n;j++)
		{
			xo^=a[j];
			if(xo==k)
			{
				t[++tmp].st=i;
				t[tmp].en=j;
				break;
			} 
		}
	}
	sort(t+1,t+1+tmp,cmp);
	if(tmp==0)
	{
		cout<<0;
		return;
	}
	int no=t[1].en;
	f=1;
	for(int i=2;i<=tmp;i++)
	{
		if(t[i].st>no)
		{
			f++;
			no=t[i].en;
		}
	}
	cout<<f<<endl;
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) pd1=false;
		if(a[i]>1) pd2=false;
		if(a[i]==1) c++;
	}
	if(pd1==true)
	{
		cout<<n/2;
		return 0;
	}
	if(pd2==true)
	{
		cout<<c;
		return 0;
	}
	solve();
	return 0;
}
