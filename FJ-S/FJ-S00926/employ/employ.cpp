#include<bits/stdc++.h>
using namespace std;
int a[510];
int n,m,rq=0;
string s;
int ans=0;
int f(int x,int d)
{
	if(x>n||d>s.size()+1)
	{
		return 0;
	}
	if(rq==m)
	{
		ans++;
		return 0;
	}
	if(s[d]=='1'&&rq<=m&&a[x]>0)
	{
		rq++;
		f(x+1,d+1);
		rq--;
		f(x+1,d+1);
	}
	else if(s[d]=='0')
	{
		for(int i=d+1;i<=n;i++)
		{
			a[i]--;
		}
		f(x+1,d+1);
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	f(1,0);
	cout<<ans+2<<endl;
	return 0;
}


