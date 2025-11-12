#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

inline int read()
{
	int x=0,r=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') r=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*r;
}

inline string read1()
{
	string re="";
	char ch=getchar();
	while(!islower(ch))
	{
		ch=getchar();
	}
	while(islower(ch))
	{
		re+=ch;
		ch=getchar();
	}
	return re;
}

bool bg;

unsigned ll d=51971;

unsigned ll hsh[5000005][2];
unsigned ll pre[5000005];


ull cut(int l,int r,int op)
{
	return hsh[r][op]-hsh[l-1][op]*pre[r-l+1];
}

int n,q;
int nw=0;

int tr[5000005][26];
int fail[5000005];
int fl[5000005];
int fa[5000005];
int typ[5000005];
int dep[5000005];
bool re[5000005];

int hsh1[10000005];
int hsh2[10000005];
int hsh3[10000005];

const int mo1=9999991,mo2=9999997,mo3=9999989;

bool ed;

void Push(string t)
{
	int p=0;
	for(int i=0;i<t.length();i++)
	{
		int u=t[i]-'a';
		if(!tr[p][u])
		{
			tr[p][u]=++nw;
			fa[nw]=p;
			typ[nw]=u;
			dep[nw]=dep[p]+1;
		}
		p=tr[p][u];
	}
	re[p]=1;
}

queue<int> kl;
int jkl=5e6;

void build()
{
	kl.push(0);
	while(kl.size())
	{
		int j=kl.front();
		kl.pop();
		if(dep[j]<=1) fail[j]=0;
		else
		{
			int d=fail[fa[j]];
			while(d&&(!tr[d][typ[j]])) d=fail[d];
			fail[j]=tr[d][typ[j]];
			if(re[fail[j]]) re[j]=1;
		}
		for(int i=0;i<26;i++)
		{
			if(tr[j][i])
			{
				kl.push(tr[j][i]);
			}
		}
	}
}

void work()
{
	//cerr<<((&ed)-(&bg))/1024.0/1024.0<<endl;
	pre[0]=1;
	for(int i=1;i<=5e6;i++)
	{
		pre[i]=pre[i-1]*d;
	}
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		string t1,t2;
		t1=read1();
		t2=read1();
		Push(t1);
		unsigned ll u1=0,u2=0;
		for(int j=0;j<t1.length();j++)
		{
			u1=u1*d+(t1[j]-'a'+1);
			u2=u2*d+(t2[j]-'a'+1);
		}
		ull kl=u1*pre[jkl]+u2;
		hsh1[kl%mo1]++;
		hsh2[kl%mo2]++;
		hsh3[kl%mo3]++;
	}
	//cerr<<"ok"<<endl;
	build();
	//cerr<<"ok1"<<endl;
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		t1=read1();
		t2=read1();
		int maxx=0,minn=0x3f3f3f3f;
		for(int j=0;j<t1.length();j++)
		{
			hsh[j+1][0]=hsh[j][0]*d+(t1[j]-'a'+1);
			hsh[j+1][1]=hsh[j][1]*d+(t2[j]-'a'+1);
			if(t1[j]!=t2[j])
			{
				minn=min(minn,j);
				maxx=max(maxx,j);
			}
		}
		//cout<<cut(3,4,1)<<endl;
		int p=0;
		int ans=0;
		//cerr<<"ok "<<i<<endl;
		for(int j=0;j<t1.length();j++)
		{
			int u=t1[j]-'a';
			while(p&&(!tr[p][u])) p=fail[p];
			p=tr[p][u];
			//cout<<i<<' '<<j<<' '<<p<<' '<<typ[p]<<' '<<re[p]<<endl;
			if(re[p]&&j>=maxx)
			{
				int s=p;
				while(s&&re[s]&&fl[s]!=i&&j-dep[s]+1<=minn)
				{
					//cout<<i<<' '<<s<<' '<<dep[s]<<endl;
					ull d=cut(j-dep[s]+2,j+1,0)*pre[jkl]+cut(j-dep[s]+2,j+1,1);
					//if(mp[d]==0) break;
					ans+=min(hsh1[d%mo1],min(hsh2[d%mo2],hsh3[d%mo3]));
					fl[s]=i;
					s=fail[s];
				}
			}
		}
		printf("%d\n",ans);
	}
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	//T=read();
	while(T--) work();
	return 0;
}
