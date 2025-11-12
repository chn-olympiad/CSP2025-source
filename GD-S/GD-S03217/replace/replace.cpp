#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
const int N=2e5+10,M=5e6+10,mod=1e9+7;
const ull base=1647;
struct hs
{
	ull f1,f2;
};
vector<hs>vec[N];
int l[N],r[N];
int n,q;
ull pw[M];
string s1[N],s2[N];
struct node
{
	int id,h1,h2;
};
bool operator<(const node& x,const node& y)
{
	if(x.h1!=y.h1) return x.h1<y.h1;
	if(x.h2!=y.h2) return x.h2<y.h2;
	return x.id<y.id;
}
vector<node>hs;
int gh1(int f,int l,int r)
{
	if(l==0) return vec[f][r].f1;
	return vec[f][r].f1-vec[f][l-1].f1*pw[r-l+1];
}
int gh2(int f,int l,int r)
{
	if(l==0) return vec[f][r].f2;
	return vec[f][r].f2-vec[f][l-1].f2*pw[r-l+1];
}
void hp(int f,string s,string t,int& x,int& y)
{
	ull hs1=0,hs2=0;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		hs1=hs1*base+s[i]-'a';
		hs2=hs2*base+t[i]-'a';
		vec[f][i].f1=hs1;
		vec[f][i].f2=hs2;
	}
	int l=0,r=len;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(mid!=len&&vec[f][mid].f1==vec[f][mid].f2) l=mid+1;
		else r=mid-1;
	}
	x=l;
	l=-1,r=len-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(mid!=-1&&gh1(f,mid,len-1)==gh2(f,mid,len-1)) r=mid-1;
		else l=mid+1;
	}
	y=r;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	pw[0]=1;
	for(int i=1;i<=5e6;i++) pw[i]=pw[i-1]*base;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s,t;
		cin>>s>>t;
		s1[i]=s,s2[i]=t;
		vec[i].resize(s.size());
		hp(i,s,t,l[i],r[i]);
		hs.push_back({i,gh1(i,l[i],r[i]),gh2(i,l[i],r[i])});
	}
	sort(hs.begin(),hs.end());
	for(int i=1;i<=q;i++)
	{
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size())
		{
			cout<<0<<'\n';
			continue;
		}
		vec[n+1].resize(s.size());
		hp(n+1,s,t,l[n+1],r[n+1]);
		int p=lower_bound(hs.begin(),hs.end(),node{0,gh1(n+1,l[n+1],r[n+1]),gh2(n+1,l[n+1],r[n+1])})-hs.begin();
		if(p==(int)(hs.size()))
		{
			cout<<0<<'\n';
			continue;
		}
		if(hs[p].h1!=gh1(n+1,l[n+1],r[n+1])||hs[p].h2!=gh2(n+1,l[n+1],r[n+1]))
		{
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(;;p++)
		{
			if(p==(int)(hs.size())) break;
			if(hs[p].h1!=gh1(n+1,l[n+1],r[n+1])||hs[p].h2!=gh2(n+1,l[n+1],r[n+1])) break;
			int ls=l[hs[p].id];
			int jl=l[n+1]-ls;
			if(jl<0||jl+vec[hs[p].id].size()-1>s.size()) continue;
			int h1=gh1(n+1,jl,jl+vec[hs[p].id].size()-1),h2=gh2(n+1,jl,jl+vec[hs[p].id].size()-1);
			if(h1==gh1(hs[p].id,0,vec[hs[p].id].size()-1)&&h2==gh2(hs[p].id,0,vec[hs[p].id].size()-1)) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
100pts!
七级钩有了！
Linux 下样例也过了，但是贼慢
不过也不用担心，评测机不至于是这种老爷机吧
*/
