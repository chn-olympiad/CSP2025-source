#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=200002+5;
LL n,q;
struct S{
	LL st,ed;
};
vector<S>d[N][2];
/*
bool cmp(S x,S y)
{
	if(x.d!=y.d)return x.d<y.d;
	else if(x.st!=y.st)return x.st<y.st;
	return x.ed<y.ed;
}*/
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		LL t1,t2;
		for(int j=0;j<a[i].size();j++)
		{
			if(a[i][j]=='b')
			{t1=j;}
			if(b[i][j]=='b')
			{t2=j;}
		}
		if(t2>t1)
		{
			d[t2-t1][0].push_back({t1,b[i].size()-1-t2});
		}
		else
		{
			d[t1-t2][1].push_back({t2,a[i].size()-1-t1});
		}
	}
	for(int i=1;i<=q;i++)
	{
		string xx,yy;
		LL t1,t2,ans=0;
		cin>>xx>>yy;
		if(xx.size()!=yy.size())
		{cout<<0<<endl;continue;}
		for(int j=0;j<xx.size();j++)
		{
			if(xx[j]=='b')
			{t1=j;}
			if(yy[j]=='b')
			{t2=j;}
		}
		LL de=t2-t1;
		if(de>0)
		{
			LL st=t1,ed=xx.size()-t2-1;
			for(int j=0;j<d[de][0].size();j++)
			{
				if(d[de][0][j].st<=st&&d[de][0][j].ed<=ed)
				{
					ans++;
				}
			}
		}
		if(de<=0)
		{
			de=-de;
			LL st=t2,ed=xx.size()-t1-1;
			for(int j=0;j<d[de][1].size();j++)
			{
				if(d[de][1][j].st<=st&&d[de][1][j].ed<=ed)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
