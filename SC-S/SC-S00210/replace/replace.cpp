#include<bits/stdc++.h>
using namespace std;
string s1[200006],s2[200005],t1,t2;
int ans,l1,l2,n,q;
void dfs(int x,int y)
{
	int l=s1[y].size();
	for(int i=x;i<=x+l;i++)
	{
		t1[i]=s2[y][i];
	}
	if(t1==t2) 
	{
		ans++;
		for(int i=x;i<=x+l;i++)
		{
			t1[i]=s1[y][i];
		}
		return;
	}
	for(int i=0;i<l1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int l3=s1[j].size();
			if(l3+i>n+1) continue;
			string u=t1.substr(i,l3);
			if(u==s1[j])
			{
				dfs(i,j);
			}
		}
	}
	for(int i=x;i<=x+l;i++)
	{
		t1[i]=s1[y][i];
	}
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int ik=1;ik<=q;ik++)
	{	
		ans=0;
		cin>>t1>>t2;
		l1=t1.size(),l2=t2.size();
		if(l1!=l2) 
		{
			cout<<0<<endl;
			continue;
		}
		for(int k=0;k<l1;k++)
		{
			for(int j=1;j<=n;j++)
			{
				int l3=s1[j].size();
				if(l3+k>n+1) continue;
				string u=t1.substr(k,l3);
				cout<<u<<endl;
				if(u==s1[j])
				{
					dfs(k,j);
					//cout<<k<<" "<<j<<endl;
				}
			}
		}
		//cout<<ans<<endl;
	}
	return 0;
} 
