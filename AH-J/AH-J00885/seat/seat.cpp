#include<bits/stdc++.h>
using namespace std;
int a[200];
int s,p,f,t;
bool cmp(int w,int q)
{
	return w<q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
			cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
			if(p==a[i])
				s=i;
	int e;
	e=s/n;
	int r;
	r=s%n;
	if(e==0)
	{
		cout<<1<<" "<<r;
		return 0;
	}
	f=1,t=1;
	for(int i=1;i<=s;i++)
	{
		if(f%2==1&&t<n)t++;
		else if(f%2==0&&t>0)t--;
		else if(t==n)f++;
		else if(t==1)f++;
	}
	cout<<t<<" "<<f;
	return 0;
}
