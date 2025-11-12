#include<bits/stdc++.h>
using namespace std;
struct datay
{
	int x,y,v1;
}d[200005];
struct datay1
{
	int x,y,v,v1;
}t[5000005];
int n,m,to[5000005][26],to1[5000005][26],num,num1,fail[5000005],fail1[5000005],q,q1,q2,q3;
int dfn[5000005],out[5000005],dfn1[5000005],out1[5000005];
long long f[200005],f1[5000015],h;
char c=' ',t1[5000005],t2[5000005];
queue<int> l;
vector<int> a[5000005],a1[5000005];
vector<datay1> b[5000005],l2[5000005];
vector<datay> l1[5000005];
set<int> p1;
map<int,int> p2;
int lowbit(int x){return x&(-x);}
void modify(int x,int v)
{
	x++;
	while(x<=5000005)f1[x]+=v,x+=lowbit(x);
	return;
}
long long query(int x)
{
	h=0,x++;
	while(x)h+=f1[x],x-=lowbit(x);
	return h;
}
void cle(int x)
{
	x++;
	while(x<=5000005)f1[x]=0,x+=lowbit(x);
	return;
}
void AC()
{
	int x;
	for(int i=0;i<26;i++)
		if(to[0][i])l.push(to[0][i]);
	while(l.size())
	{
		x=l.front(),l.pop();
		for(int i=0;i<26;i++)
		{
			if(to[x][i])
			{
				fail[to[x][i]]=to[fail[x]][i];
				l.push(to[x][i]);
			}
			else to[x][i]=to[fail[x]][i];
		}
	}
	return;
}
void AC1()
{
	int x;
	for(int i=0;i<26;i++)
		if(to1[0][i])l.push(to1[0][i]);
	while(l.size())
	{
		x=l.front(),l.pop();
		for(int i=0;i<26;i++)
		{
			if(to1[x][i])
			{
				fail1[to1[x][i]]=to1[fail1[x]][i];
				l.push(to1[x][i]);
			}
			else to1[x][i]=to1[fail1[x]][i];
		}
	}
	return;
}
void dfs(int x)
{
	dfn[x]=++q;
	for(int i=0;i<a[x].size();i++)dfs(a[x][i]);
	out[x]=q;
	return;
}
void dfs1(int x)
{
	dfn1[x]=++q1;
	for(int i=0;i<a1[x].size();i++)dfs1(a1[x][i]);
	out1[x]=q1;
	return;
}
bool cmp1(datay1 x,datay1 y){return dfn[x.x]<dfn[y.x];}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	datay1 qw;int x=0,y=0;
	set<int>::iterator p3;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		x=q2=0;
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z')
		{
			if(to[x][c-'a'])x=to[x][c-'a'];
			else to[x][c-'a']=++num,x=num;
			t1[++q2]=c;
			c=getchar();
		}
		d[i].x=x;
		x=q2=0;
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z')
		{
			if(to1[x][c-'a'])x=to1[x][c-'a'];
			else to1[x][c-'a']=++num1,x=num1;
			q2++;
			if(t1[q2]!=c)d[i].v1++;
			c=getchar();
		}
		d[i].y=x;
	}
//	for(int i=0;i<=num;i++)
//	{
//		cout<<i<<':';
//		for(int j=0;j<26;j++)
//			if(to[i][j])cout<<char(j+'a')<<':'<<to[i][j]<<' ';
//		cout<<'\n';
//	}
//	for(int i=0;i<=num1;i++)
//	{
//		cout<<i<<':';
//		for(int j=0;j<26;j++)
//			if(to1[i][j])cout<<char(j+'a')<<':'<<to1[i][j]<<' ';
//		cout<<'\n';
//	}
	AC(),AC1();
//	for(int i=1;i<=num;i++)cout<<i<<':'<<fail[i]<<'\n';
//	for(int i=1;i<=num1;i++)cout<<i<<':'<<fail1[i]<<'\n';
	for(int i=1;i<=num;i++)a[fail[i]].push_back(i);
	for(int i=1;i<=num1;i++)a1[fail1[i]].push_back(i);
	dfs(0),dfs1(0),q=q1=0;
//	for(int i=1;i<=num;i++)cout<<i<<':'<<dfn[i]<<' '<<out[i]<<'\n';
//	for(int i=1;i<=m;i++)
//	{
//		x=q2=0;
//		while(c<'a'||c>'z')c=getchar();
//		while(c>='a'&&c<='z')
//		{
//			x=to[x][c-'a'];
//			t[++q].x=x,t[q].v=i;
//			t1[++q2]=c;
//			c=getchar();
//		}
//		x=q2=0,q3=q1+1;
//		while(c<'a'||c>'z')c=getchar();
//		while(c>='a'&&c<='z')
//		{
//			x=to1[x][c-'a'];
//			t[++q1].y=x,q2++;
//			if(t1[q2]!=c)t[q3].v1++;
//			c=getchar();
//		}
//		for(int j=q3+1;j<=q1;j++)t[j].v1=t[q3].v1;
//	}
	for(int i=1;i<=m;i++)
	{
		x=y=q1=q2=q3=0;
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z')t1[++q1]=c,c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z')t2[++q2]=c,c=getchar();
		if(q1!=q2)continue;
		for(int j=1;j<=q1;j++)
			if(t1[j]!=t2[j])q3++;
		for(int j=1;j<=q1;j++)
		{
			x=to[x][t1[j]-'a'],y=to1[y][t2[j]-'a'];
			t[++q].x=x,t[q].y=y,t[q].v=i,t[q].v1=q3;
		}
	}
//	for(int i=1;i<=n;i++)cout<<dfn[d[i].x]<<' '<<out[d[i].x]<<' '<<dfn1[d[i].x]<<' '<<out1[d[i].y]<<' '<<d[i].v1<<'\n';
//	for(int i=1;i<=q;i++)cout<<dfn[t[i].x]<<' '<<dfn1[t[i].y]<<' '<<t[i].v<<' '<<t[i].v1<<'\n';
//	for(int i=1;i<=m;i++)cout<<t[i].v1<<'\n';
//	for(int i=1;i<=q;i++)cout<<i<<':'<<dfn[t[i].x]<<' '<<dfn1[t[i].y]<<' '<<t[i].v<<'\n';
	for(int i=1;i<=n;i++)l1[d[i].v1].push_back(d[i]);
	for(int i=1;i<=q;i++)l2[t[i].v1].push_back(t[i]);
	for(int k=1;k<=5000000;k++)
	{
		if(l2[k].size()==0||l1[k].size()==0)continue;
		sort(l2[k].begin(),l2[k].end(),cmp1);
		n=l1[k].size(),p1.clear(),p2.clear(),x=q1=0;
		for(int i=0;i<n;i++)l1[k][i].v1=out[l1[k][i].x]+1,l1[k][i].x=dfn[l1[k][i].x],p1.insert(l1[k][i].v1),p1.insert(l1[k][i].x);
		for(int i=0;i<l2[k].size();i++)l2[k][i].x=dfn[l2[k][i].x],p1.insert(l2[k][i].x);
		for(p3=p1.begin();p3!=p1.end();p3++)p2[*p3]=++x;
		for(int i=0;i<n;i++)l1[k][i].v1=p2[l1[k][i].v1],l1[k][i].x=p2[l1[k][i].x];
		for(int i=0;i<l2[k].size();i++)l2[k][i].x=p2[l2[k][i].x];
//		cout<<k<<":\n";
//		for(int i=0;i<n;i++)cout<<l1[k][i].x<<' '<<l1[k][i].v1<<' '<<dfn1[l1[k][i].y]<<' '<<out1[l1[k][i].y]<<'\n';
//		for(int i=0;i<l2[k].size();i++)cout<<l2[k][i].x<<' '<<dfn1[l2[k][i].y]<<' '<<l2[k][i].v<<'\n';
		for(int i=0;i<n;i++)
		{
			qw.x=dfn1[l1[k][i].y],qw.y=out1[l1[k][i].y],qw.v=1;
			b[l1[k][i].x].push_back(qw);
			qw.v=-1,b[l1[k][i].v1].push_back(qw);
		}
//		for(int i=1;i<=10;i++)
//		{
//			cout<<i<<":";
//			for(int j=0;j<b[i].size();j++)cout<<b[i][j].x<<'&'<<b[i][j].y<<' ';
//			cout<<'\n';
//		}
		for(int i=0;i<l2[k].size();i++)
		{
			while(q1<l2[k][i].x)
			{
				q1++;
				for(int j=0;j<b[q1].size();j++)modify(b[q1][j].x,b[q1][j].v),modify(b[q1][j].y+1,-b[q1][j].v);
			}
			f[l2[k][i].v]+=query(dfn1[l2[k][i].y]);
//			if(l2[k][i].v==5)cout<<query(dfn1[l2[k][i].y])<<' '<<l2[k][i].v<<'\n';
//			if(k==2)cout<<f[l2[k][i].v]<<'\n';
		}
		for(int i=0;i<=x;i++)
		{
			for(int j=0;j<b[i].size();j++)cle(b[i][j].x),cle(b[i][j].y+1);
			b[i].clear();
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		qw.x=dfn1[d[i].y],qw.y=out1[d[i].y],qw.v=1;
//		b[dfn[d[i].x]].push_back(qw);
//		qw.v=-1,b[out[d[i].x]+1].push_back(qw);
////		cout<<d[i].x<<' '<<d[i].y<<' '<<dfn[d[i].x]<<' '<<out[d[i].x]<<' '<<dfn1[d[i].y]<<' '<<out1[d[i].y]<<'\n';
//	}
//	sort(t+1,t+q+1,cmp1),q1=0;
//	for(int i=1;i<=q;i++)
//	{
//		while(q1<dfn[t[i].x])
//		{
//			q1++;
//			for(int j=0;j<b[q1].size();j++)modify(b[q1][j].x,b[q1][j].v),modify(b[q1][j].y+1,-b[q1][j].v);
//		}
//		f[t[i].v]+=query(dfn1[t[i].y]);
//	}
	for(int i=1;i<=m;i++)printf("%lld\n",f[i]);
	







  return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
