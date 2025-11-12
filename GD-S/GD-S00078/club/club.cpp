#include <bits/stdc++.h>
using namespace std;
int n,ans;
int s(int a,int b,int c,int x,int d[][3])
{
	if(x==n)
	{
		return 0;
	}
	int ans=0;
	if(a<(n>>1))
	{
		ans=d[x][0]+s(a+1,b,c,x+1,d);
	}
	if(b<(n>>1))
	{
		ans=max(ans,d[x][1]+s(a,b+1,c,x+1,d));
	}
	if(c<(n>>1))
	{
		ans=max(ans,d[x][2]+s(a,b,c+1,x+1,d));
	}
	return ans;
}
void f()
{
	cin>>n;
	int a[n][3];
	int cn=0;
	for(int x=0;x<n;x++)
	{
		cin>>a[x][0]>>a[x][1]>>a[x][2];
	}
	cout<<s(0,0,0,0,a)<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int u=0;u<t;u++)
	{
		f();
	}
	fclose(stdin);
	fclose(stdout);
}
