#include<bits/stdc++.h>
using namespace std;
int n,m;
int tir1[5000005][26],ji1,tir2[5000005][26],ji2,f1[5000005],f2[5000005],b1[5000005],b2[5000005];
string a,b;
void build1(string x,int w)
{
	int now=0;
	for(int i=0;i<x.size();i++)
	{
		if(tir1[now][x[i]-'a'] != 0) now=tir1[now][x[i]-'a'];
		else
		{
			tir1[now][x[i]-'a']=++ji1;
			now=ji1;
		}
	}
	f1[now]++;
	b1[now]=w;
}
void build2(string x,int w)
{
	int now=0;
	for(int i=0;i<x.size();i++)
	{
		if(tir2[now][x[i]-'a'] != 0) now=tir2[now][x[i]-'a'];
		else
		{
			tir2[now][x[i]-'a']=++ji2;
			now=ji2;
		}
	}
	f2[now]++;
	b2[now]=w;
}
int find(int ip,string x,string y,int maxi)
{
	int na=0,nb=0;
	while(ip < x.size())
	{
		if(tir1[na][x[ip]-'a'] != 0 && tir2[nb][y[ip]-'a'] != 0)
		{
			na=tir1[na][x[ip]-'a'];
			nb=tir2[nb][y[ip]-'a'];
			ip++;
		}
		else
		{
			if(ip > maxi && b1[na] == b2[nb]) return f1[na];
			return 0;
		}
	}
	if(ip > maxi && b1[na] == b2[nb]) return f1[na];
	return 0;
}
int anser(string x,string y)
{
	int xs=x.size(),ys=y.size(),maxi=0,mini=xs,ans=0;
	if(xs != ys) return 0;
	for(int i=0;i<xs;i++)
		if(x[i] != y[i]) maxi=max(maxi,i),mini=min(mini,i);
	for(int i=0;i<=mini;i++)
		if(tir1[0][x[i]-'a'] != 0 && tir2[0][y[i]-'a'] != 0)
			ans+=find(i,x,y,maxi);
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n <= 100 && m <= 100)
	{
		string a_[105],b_[105],a1_,b1_;
		for(int i=1;i<=n;i++)
			cin>>a_[i]>>b_[i];
		for(int i=1;i<=m;i++)
		{
			cin>>a1_>>b1_;
			if(a1_.size() != b1_.size())
			{
				printf("0\n");
				continue;
			}
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				for(int k=0;k<a1_.size();k++)
					if(a1_.substr(k,a_[j].size()) == a_[j] && b1_.substr(k,b_[j].size()) == b_[j])
						if(a1_.substr(0,k) == b1_.substr(0,k) && a1_.substr(k+a_[j].size()) == b1_.substr(k+b_[j].size()))
							ans++;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		build1(a,i);
		build2(b,i);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		printf("%d\n",anser(a,b));
	}
	return 0;
}
