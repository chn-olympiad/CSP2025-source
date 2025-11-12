#include<bits/stdc++.h>
#define rg register int
#define fo(i,l,r) for(rg i=(l);i<=(r);i++)
#define dfo(i,r,l) for(rg i=(r);i>=(l);i--)
#define fe(i,x) for(rg i=hd[x];i;i=nex[i])
#define frein freopen("in.txt","r",stdin)
#define freout freopen("out.txt","w",stdout)
#define fre(p) freopen(#p".in","r",stdin),freopen(#p".out","w",stdout)
#define vi vector<int>
#define eb emplace_back
#define pii pair<int,int>
#define fir first
#define sec second
#define mkp make_pair
#define i8 __int128
#define db double
#define ll unsigned long long
using namespace std;
bool deb=1,Mst;
void ck_(){cerr<<"\n";}
template<typename T,typename...R>
void ck_(T x,R...y){if(!deb)return;cerr<<x<<" ";ck_(y...);}
void Bz_(){cerr<<"---------------------------------\n";}
#define ck ck_
#define Bz Bz_()
#define outa(l,r,a) {fo(II,l,r)cerr<<a[II]<<" ";cerr<<"\n";}
#define gc() getchar()
#define pc(x) putchar(x)
inline void rd(string &a)
{
	register char c=gc();a="";
	while(c<'a'||'z'<c)c=gc();
	while('a'<=c&&c<='z')a+=c,c=gc();
}
void wt(int x)
{
	if(x<=9)pc(x+'0');
	else wt(x/10),pc(x%10+'0');
}
const int N=2e5+5,M=7e6+5;
ll bas=233,s;
string s1,s2;int l1,l2;
int n,m,x,y,t;
struct nd{string a,b;ll c;int i;}a[N],q[N];int lq,Ans[N];
vi h[M];
int lb,lc,b[M][26],rt[M],c[M][26],d[M],rf;
inline void init()
{
	fo(i,0,lb)fo(j,0,25)b[i][j]=0;
	fo(i,0,lc)fo(j,0,25)c[i][j]=0;
	fo(i,0,lb)rt[i]=0,h[i].clear();
	fo(i,0,lc)d[i]=0;
	lb=1,lc=0,rf=0;
}
inline void ins(nd o)
{
	int x=1,l=o.a.size();
	fo(i,0,l-1)
	{
		int &y=b[x][o.a[i]-'a'];
		if(y==0)y=++lb;
		x=y;
	}
	if(rt[x]==0)rt[x]=++lc;
	x=rt[x],l=o.b.size();
	fo(i,0,l-1)
	{
		int &y=c[x][o.b[i]-'a'];
		if(y==0)y=++lc;
		x=y;
	}
	d[x]++;
//	ck(o.a,o.b,o.c,x,d[x]);
}
inline void tag(nd o,int id)
{
	int x=1,l=o.a.size();
	fo(i,0,l-1)
	{
		if(b[x][o.a[i]-'a']==0)
		{
			h[x].eb(id);
			return;
		}
		x=b[x][o.a[i]-'a'];
	}
	h[x].eb(id);
}
void mg(int &x,int y)
{
	if(x==0)
	{
		x=y,d[x]=d[y];
		return;
	}
	d[x]+=d[y];
	fo(i,0,25)if(c[y][i])mg(c[x][i],c[y][i]);
}
void del(int x,int y)
{
	d[x]-=d[y];
	fo(i,0,25)if(c[y][i])del(c[x][i],c[y][i]);
}
void wk(int x)
{
	if(x==0)return;
	mg(rf,rt[x]);
	for(int o:h[x])
	{
		int z=rf,l=q[o].b.size();
		Ans[q[o].i]+=d[z];
		fo(i,0,l-1)
		{
			z=c[z][q[o].b[i]-'a'];
			Ans[q[o].i]+=d[z];
		}
	}
	fo(i,0,25)wk(b[x][i]);
	del(rf,rt[x]);
}
bool Med;
int main()
{
//	frein;
//	freout;
	fre(replace);
	cin>>n>>m;
//	ck((&Mst-&Med)/1024);
	fo(j,1,n)
	{
		rd(s1),rd(s2),l1=s1.size()-1;
		fo(i,0,l1)
		{
			x=i;
			if(s1[i]!=s2[i])break;
		}
		dfo(i,x-1,0)a[j].a+=s1[i];
		dfo(i,l1,0)
		{
			y=i;
			if(s1[i]!=s2[i])break;
		}
		fo(i,y+1,l1)a[j].b+=s1[i];
		a[j].c=0;
		fo(i,x,y)a[j].c=a[j].c*bas+s1[i];
		fo(i,x,y)a[j].c=a[j].c*bas+s2[i];
		a[j].i=j;
//		ck(a[j].a,a[j].b,a[j].c);
//		if(j==206)cout<<s1<<" "<<s2<<"\n";
	}
	fo(j,1,m)
	{
		rd(s1),rd(s2),l1=s1.size()-1,l2=s2.size()-1;
		if(l1!=l2)
		{
			Ans[j]=0;
			continue;
		}lq++;
		fo(i,0,l1)
		{
			x=i;
			if(s1[i]!=s2[i])break;
		}
		dfo(i,x-1,0)q[lq].a+=s1[i];
		dfo(i,l1,0)
		{
			y=i;
			if(s1[i]!=s2[i])break;
		}
		fo(i,y+1,l1)q[lq].b+=s1[i];
		q[lq].c=0;
		fo(i,x,y)q[lq].c=q[lq].c*bas+s1[i];
		fo(i,x,y)q[lq].c=q[lq].c*bas+s2[i];
		q[lq].i=j;
//		ck(q[lq].a,q[lq].b,q[lq].c);
//		if(j==177)cout<<s1<<" "<<s2<<"\n";
//		ck(s1);ck(s2);
	}
//	Bz;
	sort(a+1,a+1+n,[](nd a,nd b){return a.c<b.c;});
	sort(q+1,q+1+lq,[](nd a,nd b){return a.c<b.c;});
//	fo(k,1,lq)
//	{
//		int qa=q[k].a.size(),qb=q[k].b.size();
//		fo(i,1,n)if(a[i].c==q[k].c)//if(i==30399)
//		{
//			bool p=0;
//			int l=a[i].a.size();
//			if(l>qa)continue;
//			fo(j,0,l-1)if(a[i].a[j]!=q[k].a[j]){p=1;break;}
//			if(p)continue;
//			l=a[i].b.size();
//			if(l>qb)continue;
//			fo(j,0,l-1)if(a[i].b[j]!=q[k].b[j]){p=1;break;}
//			if(p==0)
//			{
//				Ans[q[k].i]++;
//				cout<<a[i].i<<" "<<a[i].a<<" "<<a[i].b<<"\n";
//			}
//		}
//	}
	int pos=1;init();
	fo(i,1,n)
	{
		ins(a[i]);
		if(i==n||a[i].c!=a[i+1].c)
		{
			while(pos<=lq&&q[pos].c<a[i].c)pos++;
			while(pos<=lq&&q[pos].c==a[i].c)
			{
				tag(q[pos],pos);
				pos++;
			}
			wk(1);
			init();
		}
	}
	fo(i,1,m)wt(Ans[i]),pc('\n');
	return 0;
}
