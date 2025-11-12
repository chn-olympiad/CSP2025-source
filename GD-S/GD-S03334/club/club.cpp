#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
//#define int long long
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],s[N],c[N];
long long ans;
priority_queue<pair<int,pair<int,pair<int,int>>>> q;
void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}
void add(int i,int x,int y)
{
	q.push(make_pair(a[i][y]-a[i][x],make_pair(i,make_pair(x,y))));
}
int get(int x,int y,int z)
{
	if(x>=y&&x>=z)return 1;
	if(y>=z)return 2;
	return 3;
}
int main()
{
	fre("club");
	read(t);
	while(t--)
	{
		while(!q.empty())q.pop();
		ans=0;
		read(n);
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)read(a[i][j]);
		s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++)
		{
			int x=get(a[i][1],a[i][2],a[i][3]);
			ans+=a[i][x];
			c[i]=x;
			s[x]++;
			for(int j=1;j<=3;j++)if(x!=j)add(i,x,j);
		}
//		int xx=0;
		while(!q.empty())
		{
//			xx++;
//			cout<<xx<<'\n';
//			cout<<s[1]<<' '<<s[2]<<' '<<s[3]<<'\n';
			int cnt=q.top().first;
			int i=q.top().second.first;
			int x=q.top().second.second.first;
			int y=q.top().second.second.second;
//			cout<<"     "<<cnt<<' '<<i<<' '<<x<<' '<<y<<'\n';
			q.pop();
			if(c[i]!=x)continue;
			if(cnt>0)
			{
				if(s[y]<n/2)
				{
					s[x]--,s[y]++,c[i]=y,ans+=cnt;
					for(int j=1;j<=3;j++)if(y!=j)add(i,y,j);
				}
			}
			else
			{
				if(s[x]>n/2)
				{
					s[x]--,s[y]++,c[i]=y,ans+=cnt;
					for(int j=1;j<=3;j++)if(y!=j)add(i,y,j);
				}
			}
		}
//		cout<<s[1]<<' '<<s[2]<<' '<<s[3]<<'\n';
//		for(int i=1;i<=n;i++)cout<<c[i]<<' ';cout<<'\n';
		printf("%lld\n",ans);//cout<<">>"<<xx<<'\n';
	}
}
