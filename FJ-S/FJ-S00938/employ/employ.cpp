#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],s;
bool a[510],b[510];
void ww(int x,int y)
{
	if(x==n+1)
	{
		cout<<x<<" "<<y<<endl;
		if(y>=m)s++;
		return;
	}
	for(int i=1;i<=n;i++)
	if(b[i]==0)
	{
		b[i]=true;
		if(a[x]==0&&x-y-1<c[i])
			ww(x+1,y+1);
		else
			ww(x+1,y);
		b[i]=false;
	}
}
main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char b;
		cin>>b;
		a[i]=b-'0';
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	ww(1,0);
	cout<<s<<endl;
}
