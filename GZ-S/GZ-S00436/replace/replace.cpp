//GZ-S00436 贵阳市南明区李端棻中学 邓景一 
#include<bits/stdc++.h>
using namespace std;
string a1[200005],a2[200005],t1,t2;
int n;
int f(char x,char y)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a1[i].size();j++)
		{
			if(a1[i][j]==a2[i][j] && a1[i][j]==x && a2[i][j]==y)
				ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i]>>a2[i];
	}
	int x;
	while(q--)
	{
		cin>>t1>>t2;int l=0,r=t1.size()-1;
		while(f(t1[l],t2[l])==1)
		{
			l++;
		}
		while(f(t1[r],t2[r])==1)
			r--;
		x=f(t1[l],t2[l]);
		for(int i=l+1;i<=r-1;i++)
		{
				if(f(t1[i],t2[i])<x && f(t1[i],t2[i])!=0)
					x=f(t1[i],t2[i]);
		}
		cout<<x;
	}
	return 0;
}
