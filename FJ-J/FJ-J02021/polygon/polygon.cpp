#include<bits/stdc++.h>
using namespace std;
int ans=0;
int s[50005];
int n;
void f(int bs,int ts,int xb,int zong)
{
	if(ts==bs)
	{
		int q=xb;
		while(s[q]<zong&&q<=n)
		{
			q++;
			ans++;
		}
	}
	for(int i=xb;i<=n;i++)
	{
		f(bs,ts+1,i+1,zong+s[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=3;i<=n;i++)
	{
		f(i,1,1,0);	
	}
	cout<<ans; 
	return 0;
} 
