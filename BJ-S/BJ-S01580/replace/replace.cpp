#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define ull unsigned long long
#define lowbit(x) (x&(-x))
const int N=2e5+10,M=5e6+10,T=5e6;
const ull bs=31;
ull a[N],b[N],h1[M],h2[M],pw[M];
int d[N],pl[N],tp[N],pr[N];
vector<ull> h[N];
map<ull,bool> v1,v2;
vector<int> ps[N];
vector<PII> p[2*M];
char c1[M],c2[M];
struct ask
{
	int d,x,y,id;
}ak[N];
bool cmp(ask q,ask w)
{
	return q.d<w.d;
}
ull g1(int l,int r)
{
	if(l>r) return 0;
	return h1[r]-h1[l-1]*pw[r-l+1];
}
ull g2(int l,int r)
{
	if(l>r) return 0;
	return h2[r]-h2[l-1]*pw[r-l+1];
}
ull f1(int i,int l,int r)
{
	if(l>r) return 0;
	return h[i][r]-h[i][l-1]*pw[r-l+1];
}
ull f2(int i,int l,int r)
{
	if(l>r) return 0;
	return h[i][r]-h[i][l-1]*pw[r-l+1];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	pw[0]=1;
	for(int i=1;i<M;i++) pw[i]=pw[i-1]*bs;
	int n,q;
	cin>>n>>q;
	if(q==1||(n<=50000||q<=50000))
	{
		for(int i=1;i<=n;i++)
		{
			cin>>(c1+1)>>(c2+1);
			int m=strlen(c1+1),l=0,r=0;
			for(int j=0;j<=m;j++) h[i].push_back(0);
			for(int j=1;j<=m;j++) h[i][j]=h[i][j-1]*bs+c1[j]-'a'+1;
			for(int j=1;j<=m;j++)
				if(c1[j]!=c2[j]) r=j;
			for(int j=m;j>=1;j--)
				if(c1[j]!=c2[j]) l=j;
			if(l==0) d[i]=0;
			else d[i]=r-l+1;
			for(int j=l;j<=r;j++) a[i]=a[i]*bs+c1[j]-'a'+1,b[i]=b[i]*bs+c2[j]-'a'+1;
			pl[i]=l,pr[i]=m-r,tp[i]=r;
			v1[a[i]]=1,v2[b[i]]=1;
			ps[d[i]].push_back(i);
		}
		while(q--)
		{
			cin>>(c1+1)>>(c2+1);
			int m=strlen(c1+1),l=0,r=0,ans=0;
			ull s1=0,s2=0;
			for(int j=1;j<=m;j++)
				if(c1[j]!=c2[j]) r=j;
			for(int j=m;j>=1;j--)
				if(c1[j]!=c2[j]) l=j;
			for(int j=l;j<=r;j++) s1=s1*bs+c1[j]-'a'+1,s2=s2*bs+c2[j]-'a'+1;
			for(int i=1;i<=m;i++) h1[i]=h1[i-1]*bs+(c1[i]-'a'+1),h2[i]=h2[i-1]*bs+(c2[i]-'a'+1);
			if(v1[s1]==0||v2[s2]==0)
			{
				cout<<"0"<<'\n';
				continue;
			}
			for(int i:ps[r-l+1])
			{
				if(a[i]!=s1||b[i]!=s2) continue;
				if(pl[i]>l||pr[i]>m-r) continue;
				if(g1(l-pl[i]+1,l-1)!=f1(i,1,pl[i]-1)||g2(r+1,r+pr[i])!=f2(i,tp[i]+1,tp[i]+pr[i])) continue;
				ans++;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>(c1+1)>>(c2+1);
		int m=strlen(c1+1);
		for(int j=1;j<=m;j++)
			if(c1[j]=='b') a[i]=j;
		for(int j=1;j<=m;j++)
			if(c2[j]=='b') b[i]=j;
		p[a[i]-b[i]+T].push_back({a[i],m-a[i]});
	}
	for(int i=0;i<=2*T;i++) sort(p[i].begin(),p[i].end());
	while(q--)
	{
		cin>>(c1+1)>>(c2+1);
		int p1=0,p2=0,m=strlen(c1+1);
		for(int j=1;j<=m;j++)
			if(c1[j]=='b') p1=j;
		for(int j=1;j<=m;j++)
			if(c2[j]=='b') p2=j;
		int ans=0;
		for(PII t:p[p1-p2+T])
		{
			if(t.first>p1) break;
			if(t.first<=p1&&t.second<=m-p1) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
