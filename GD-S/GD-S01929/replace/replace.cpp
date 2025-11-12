#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;
const int N=5000005,M=200005;
int q[N],l,r;
vector<int> E1[N],E2[N];
ll res[N]; 
struct ACAM{
	int tr[N][26],fail[N];
	int I[N];
	int tot;
	void ins(char *s,int n,int id)
	{
		int u=0;
		for(int i=1;i<=n;i++)
		{
			int c=s[i]-'a';
			if(!tr[u][c]) tr[u][c]=++tot;
			u=tr[u][c];
		}
		I[u]=id;
	}
	void gfail()
	{
		l=1,r=0;
		for(int i=0;i<26;i++)
			if(tr[0][i]) q[++r]=tr[0][i];
		while(l<=r)
		{
			int u=q[l++];
			for(int i=0;i<26;i++)
				if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q[++r]=tr[u][i];
				else tr[u][i]=tr[fail[u]][i];
		}
	}
	void build(vector<int>*E)
	{
		for(int i=1;i<=tot;i++) E[fail[i]].pb(i);
	}
}A,B;
struct BIT{
	ll tr[N];
	int n;
	void add(int l,int r,int w){add(l,w),add(r+1,-w);}
	void add(int x,int w)
	{
		while(x<=n)
		{
			tr[x]+=w;
			x+=x&-x;
		}
	}
	int ask(int x)
	{
		ll sum=0;
		while(x)
		{
			sum+=tr[x];
			x-=x&-x;
		}
		return sum;
	}
}T;
char s[N],t[N];
int n,m;
struct ques{
	int u,id;
};
vector<ques>Q[N];
int L[N],R[N],tim;
int bd[N];
void bdfs(int u)
{
	L[u]=++tim;bd[B.I[u]]=u;
	for(int v:E2[u]) 
		bdfs(v);
	R[u]=tim;
}
void adfs(int u)
{
	if(A.I[u]) T.add(L[bd[A.I[u]]],R[bd[A.I[u]]],1); 
	for(int v:E1[u]) 
		adfs(v);
	for(ques q:Q[u])
		res[q.id]+=T.ask(L[q.u]);
	if(A.I[u]) T.add(L[bd[A.I[u]]],R[bd[A.I[u]]],-1); 
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s+1,t+1);
		A.ins(s,strlen(s+1),i);
		B.ins(t,strlen(t+1),i);
	}
	A.gfail();A.build(E1);
	B.gfail();B.build(E2);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%s",s+1,t+1);
		int ls=strlen(s+1),rs=strlen(t+1);
		if(ls^rs) continue;
		int lu=0,ru=0;
		int rp=0,lp=0;
		for(int j=ls;j>=1;j--)
			if(s[j]^t[j])
			{
				rp=j;
				break;
			}
		for(int j=1;j<=ls;j++)
			if(s[j]^t[j])
			{
				lp=j-1;
				break;
			}
		for(int j=1;j<=ls;++j)
		{
			lu=A.tr[lu][s[j]-'a'];
			ru=B.tr[ru][t[j]-'a'];
			if(j>=rp) Q[lu].pb((ques){ru,i});
		}
	}
	T.n=B.tot+1;
	bdfs(0);
	adfs(0);
	for(int i=1;i<=m;i++) printf("%lld\n",res[i]);
	return 0;
} 
