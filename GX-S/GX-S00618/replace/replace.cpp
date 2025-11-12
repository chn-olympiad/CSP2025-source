#include<bits/stdc++.h>
using namespace std;
int n,q,h[5000005],kx[5000005],ky[5000005];
map<string,string> vis;
map<pair<int,int>,pair<int,int> > bj;
void Change(string s,int &x,int &y,bool u=false)
{
	bool vis=false;
	for(auto i:s)
	{
		if(i=='b')
			vis=true;
		else if(vis)
			x++;
		else
			y++;
	}
	if(!u)
		kx[x]++,ky[y]++;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		vis[a]=b;
		if(n>10000)
		{
			int x=0,y=0,l=0,r=0;
			Change(a,x,y),Change(b,l,r,1);
			bj[{x,y}]={l,r};
		}
	}
	for(int i=1;i<=5000000;i++)
		kx[i]=kx[i-1]+kx[i],ky[i]=ky[i-1]+ky[i];
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		if(n>10000)
		{
			int x=0,y=0,l=0,r=0;
			Change(a,x,y),Change(b,l,r,1);
			cout<<min(kx[x],ky[y])<<'\n';
			continue;
		}
		int s1=a.size(),s2=b.size();
		if(s1!=s2)
		{
			puts("0");
			continue;
		}
		for(int i=0;i<s1;i++)
			h[i]=h[i-1]+(a[i]!=b[i]);
		int ans=0;
		for(int i=0;i<s1;i++)
		{
			string sum1,sum2;
			bool k=0;
			for(int j=i;j<s1;j++)
			{
				if(a[j]!=b[j])
					k=1;
				sum1+=a[j],sum2+=b[j];
				if(h[i-1]==0&&h[s1-1]-h[j]==0&&k&&vis[sum1]==sum2)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
