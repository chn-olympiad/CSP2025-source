//GZ-S00159 北京师范大学贵阳附属中学 张景奕 
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7,M=5e6+9;
int n,m;
typedef unsigned long long ul;
string aa[N],bb[N];
ul a[N],b[N],x[N],y[N];
int u[N],v[N];
string c,d;
ul w[M];
const ul P=51263;
ul di[N]={1,P};
#define ff first
#define ss second
typedef pair<ul,ul> puu;
multimap <puu,int> mm;
int main()
{
	for(int i=2;i<N;i++)
	{
		di[i]=di[i-1]*P;
	}
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i]>>bb[i];
		int l=0,r=aa[i].size()-1;
		for(int j=0;j<aa[i].size();j++)
		{
			a[i]=a[i]*P+(aa[i][j]-'a'+1);
			b[i]=b[i]*P+(bb[i][j]-'a'+1);
			if(aa[i][j]!=bb[i][j])
			{
				if(!l) l=j;
				r=j;
			}
		}
		if(aa[i][0]!=bb[i][0]) l=0;
		u[i]=l;
		v[i]=aa[i].size()-1-r;
		for(int j=l;j<=r;j++)
		{
			x[i]=x[i]*P+(aa[i][j]-'a'+1);
			y[i]=y[i]*P+(bb[i][j]-'a'+1);
		}
		mm.insert({{x[i],y[i]},i});
	}
	while(m--)
	{
		cin>>c>>d;
		if(c.size()!=d.size())
		{
			cout<<"0\n";
			continue;
		}
		
		int l=0,r=c.size()-1;
		for(int j=0;j<c.size();j++)
		{
			if(c[j]!=d[j])
			{
				if(!l) l=j;
				r=j;
			}
			w[j]=w[j-1]*P+(c[j]-'a'+1);
		}
		if(c[0]!=d[0]) l=0;
		ul cut=0,fix=0;
		for(int i=l;i<=r;i++)
		{
			cut=cut*P+(c[i]-'a'+1);
			fix=fix*P+(d[i]-'a'+1);
		}
		if(!mm.count({cut,fix}))
		{
			cout<<"0\n";
			continue;
		}
		
		int cnt=0;
		for(auto e=mm.find(make_pair(cut,fix));
			e!=mm.end()&&
			e->ff==make_pair(cut,fix);
			e++
		)
		{
			int id=e->ss;
			int ll=l-u[id];
			if(ll<0) continue;
			int rr=r+v[id];
			if(rr>=c.size())
				continue;
			ul need=w[rr]-w[ll-1]*di[rr-ll+1];
			if(need==a[id])
				cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
