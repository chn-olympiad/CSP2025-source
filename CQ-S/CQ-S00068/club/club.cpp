#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define rep1(i,l,r) for(int i=l;i<=r;++i)
#define rep2(i,l,r) for(int i=l;i>=r;--i)
#define rep3(i,h,x,ne) for(int i=h[x];~i;i=ne[i])
#define rep4(x,v) for(auto x:v)
const int N=2e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
using namespace std;
int T,n,a[N][3];
pii t[N];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool cmp(pii a,pii b){return a.x-a.y>b.x-b.y;}
void getans()
{
	n=read();
	rep1(i,1,n) rep1(j,0,2) a[i][j]=read();
	int ans=inf;
	rep1(j,0,2)
	{
		rep1(i,1,n)
		{
			t[i]=make_pair(-inf,-inf);
			rep1(k,0,2)
			{
				if(k==j) t[i].x=a[i][k];
				else t[i].y=max(t[i].y,a[i][k]); 
			}
		}
		sort(t+1,t+n+1,cmp);
		int now=0;
		rep1(i,1,n/2) 
		{
			if(t[i].x>=t[i].y) now+=t[i].x;
			else now+=t[i].y;
		}
		rep1(i,n/2+1,n) now+=t[i].y;
		ans=min(ans,now);
	}
	cout<<ans<<"\n";
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) getans();
	return 0;
}
/*
2
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
