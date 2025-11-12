#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,l,r,ans;
//bool txb=true;
string x,y;
map<string,map<string,int> >mp;
//map<int,int>bwy;

struct relationship
{
	string start;
	string to;
	int l;
	int r;
	int bw;
}a[200001];

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].start>>a[i].to;
//		if(!txb) continue;
//		int aa=0,bb=0;
//		for(int j=0;j<a[i].start.size();++j)
//		{
//			if(a[i].start[j]=='a') ++aa;
//			else if(a[i].start[j]=='b') ++b;
//			else
//			{
//				txb=false;
//				break;
//			}
//		}
//		if(!txb) continue;
//		if(bb!=1)
//		{
//			txb=false;
//			continue;
//		}
//		aa=0;
//		bb=0
//		for(int j=0;j<a[i].to.size();++j)
//		{
//			if(a[i].to[j]=='a') ++aa;
//			else if(a[i].to[j]=='b') ++b;
//			else
//			{
//				txb=false;
//				break;
//			}
//		}
//		a[i].bw=a[i].start.find('b')-a[i].to.find('b');
//		++bwy[a[i].bw];
	}
	for(int i=1;i<=n;++i)
	{
		l=a[i].start.size();
		r=-1;
		for(int j=0;j<a[i].start.size();++j)
		{
			if(a[i].start[j]==a[i].to[j]) continue;
			l=min(l,j);
			r=max(r,j);
		}
		a[i].l=l;
		a[i].r=r;
		++mp[a[i].start][a[i].to];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>x>>y;
		ans=0;
		if(x.size()!=y.size())
		{
			cout<<"0\n";
			continue;
		}
		l=x.size();
		r=-1;
		for(int j=0;j<x.size();++j)
		{
			if(x[j]==y[j]) continue;
			l=min(l,j);
			r=max(r,j);
		}
		if(m==1||n*m<=10000000)
		{
			for(int j=1;j<=n;++j)
			{
				if(x.find(a[j].start)==-1||y.find(a[j].to)==-1||x.find(a[j].start)!=y.find(a[j].to)) continue;
				if(x.find(a[j].start)>l||x.find(a[j].start)+a[j].start.size()-1<r) continue;
				++ans;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int j=l;j>=0;--j)
		{
			for(int u=r;u<x.size();++u)
			{
				string q=x.substr(j,u-j+1),p=y.substr(j,u-j+1);
				if(mp[q][p]) ans+=mp[q][p];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}















