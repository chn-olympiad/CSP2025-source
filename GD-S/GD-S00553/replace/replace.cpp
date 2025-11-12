#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
#define pi pair<int,int>
#define eb emplace_back
#define vi vector<int>
#define fi first
#define se second
#define ll long long
using namespace std;
int read(){int s=0;char c=getchar();while(c<48||c>57)c=getchar();while(c>=48&&c<=57)s=(s<<3)+(s<<1)+c-48,c=getchar();return s;}
void out(int x){if(x>9)out(x/10);putchar(x%10+48);}
const int N=4e5+7,M=2500007;
int n,q,l,f[M],ans[N],len,o;
char s[M<<1],t[M<<1],tmp[M<<1];
struct msg{
	int x,y,z,bh;
}p[N],I[N<<2];
struct trie{
	int tot,c[M][26],dfn[M],cnt,sz[M];
	int ins()
	{
		int o=0;
		fo(i,1,len)
		{
			int ch=tmp[i]-'a';
			if(!c[o][ch]) c[o][ch]=++tot;
			o=c[o][ch];
		}
		return o;
	}
	int fnd()
	{
		int o=0;
		fo(i,1,len)
		{
			int ch=tmp[i]-'a';
			if(!c[o][ch]) return o;
			o=c[o][ch];
		}
		return o;
	}
	void dfs(int x)
	{
		dfn[x]=++cnt;sz[x]=1;
		fo(i,0,25) if(c[x][i]) dfs(c[x][i]),sz[x]+=sz[c[x][i]];
	}
	void bt()
	{
		dfs(0);
	}
}t1,t2;
void upd(int x,int y){while(x<=t2.cnt)f[x]+=y,x+=x&-x;}
int qry(int x){int s=0;while(x)s+=f[x],x-=x&-x;return s;}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	fo(i,1,n)
	{
		l=0;
		char c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while(c>='a'&&c<='z') s[++l]=c,c=getchar();
		l=0;
		c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while(c>='a'&&c<='z') t[++l]=c,c=getchar();
		int u=0,v=0;
		fo(j,1,l) if(s[j]!=t[j]) u=u?u:j,v=j;
		if(!u) continue;
		len=0;
		fd(j,v,1) tmp[++len]=s[j];
		p[i].x=t1.ins();
		len=0;
		fo(j,u,l) tmp[++len]=t[j];
		p[i].y=t2.ins();
		p[i].z=v-u+1;
	}
	fo(i,1,q)
	{
		l=0;
		char c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while(c>='a'&&c<='z') s[++l]=c,c=getchar();
		int l2=0;
		c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while(c>='a'&&c<='z') t[++l2]=c,c=getchar();
		if(l!=l2) continue;
		int u=0,v=0;
		fo(j,1,l) if(s[j]!=t[j]) u=u?u:j,v=j;
		len=0;
		fd(j,v,1) tmp[++len]=s[j];
		p[n+i].x=t1.fnd();
		len=0;
		fo(j,u,l) tmp[++len]=t[j];
		p[n+i].y=t2.fnd();
		p[n+i].z=v-u+1;
		p[n+i].bh=i;
	}
	t1.bt();t2.bt();
	sort(p+1,p+n+q+1,[&](msg u,msg v){return u.z<v.z;});
	fo(i,1,n+q) if(p[i].z)
	{
		int j=i;
		while(j<n+q&&p[j+1].z==p[i].z) j++;
		o=0;
		fo(k,i,j)
		{
			if(!p[k].bh)
			{
				I[++o]={t1.dfn[p[k].x],t2.dfn[p[k].y],1,0};
				I[++o]={t1.dfn[p[k].x]+t1.sz[p[k].x],t2.dfn[p[k].y],-1,0};
				I[++o]={t1.dfn[p[k].x],t2.dfn[p[k].y]+t2.sz[p[k].y],-1,0};
				I[++o]={t1.dfn[p[k].x]+t1.sz[p[k].x],t2.dfn[p[k].y]+t2.sz[p[k].y],1,0};
			}
			else
			{
				I[++o]={t1.dfn[p[k].x],t2.dfn[p[k].y],0,p[k].bh};
			}
		}
		sort(I+1,I+o+1,[&](msg u,msg v){return u.x==v.x?u.bh<v.bh:u.x<v.x;});
		fo(k,1,o)
		{
			if(!I[k].bh) upd(I[k].y,I[k].z);
			else ans[I[k].bh]=qry(I[k].y);
		}
		fo(k,1,o) upd(I[k].y,-I[k].z);
		i=j;
	}
	fo(i,1,q) out(ans[i]),putchar('\n');
}
