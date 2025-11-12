#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7,MAXLENTH=2.5e6+7;
struct node
{
	string x,to;
	int siz;
}mapp,q;
struct zdtree
{
	int cnt;
	map<short,int> son;
}a[MAXLENTH];
int n,que,L1,L2,ed,temp,tot=1,ans;
string x;
string y;
int f(char x,char y)
{
	return (x-'a')*26+(y-'a');
}
void add(int root,int d)
{
	if(d==mapp.siz)
	{
		a[root].cnt++;
		return;
	}
	temp=f(mapp.x[d+1],mapp.to[d+1]);
	if(a[root].son[temp]==0)
	{
		tot++;
		a[root].son[temp]=tot;
	}
	add(a[root].son[temp],d+1);
}
void getans(int root,int d)
{
	if(d>=ed) ans+=a[root].cnt;
	temp=f(q.x[d+1],q.to[d+1]);
	if(a[root].son[temp]==0) return;
	getans(a[root].son[temp],d+1);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> que;
	int i,j,k;
	for(i=1;i<=n;i++) 
	{
		cin >> mapp.x >> mapp.to;
		mapp.siz=mapp.x.size();
		mapp.x=" "+mapp.x;
		mapp.to=" "+mapp.to;
		L1+=mapp.siz*2;
		add(1,0);
	}
	for(i=1;i<=que;i++)
	{
		cin >> q.x >> q.to;
		q.siz=q.x.size();
		q.x=" "+q.x;
		q.to=" "+q.to;
		for(j=q.siz;j>=1;j--)
		{
			if(q.x[j]!=q.to[j])
			{
				ed=j;
				break;
			}
		}
		ans=0;
		for(j=1;j<=q.siz;j++)
		{
			getans(1,j-1);
			if(q.x[j]!=q.to[j]) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
