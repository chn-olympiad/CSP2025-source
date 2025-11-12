#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005,mod=998244353;
int n,ans;
bool book[MAXN];
struct node
{
	int num,id;
}a[MAXN];
bool cmp(node a,node b)
{
	return a.num<b.num;
}
void dfs(int num,int add,int maxn,int len)
{
//	cout<<num<<' ';
	if(len>n) return;
	book[num]=1;
	if(len>=3&&maxn*2<add)
	{
//		cout<<"now:"<<num<<' '<<add<<' '<<maxn<<' '<<len<<'\n';
		ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[a[i].id]==0&&a[i].id>num)
		{
//			cout<<"to"<<a[i].id<<'\n';
			dfs(a[i].id,add+a[i].num,max(maxn,a[i].num),len+1);
		}
		book[a[i].id]=0;
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		a[i]={num,i};
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		dfs(a[i].id,a[i].num,a[i].num,1);
		memset(book,0,sizeof(book));
	}
	cout<<ans<<'\n';
}
