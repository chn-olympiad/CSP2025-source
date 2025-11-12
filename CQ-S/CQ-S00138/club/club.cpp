


#include<bits/stdc++.h>
//#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define ff(i,a,b) for(int i=(a);i>=(b);i--)
#define sd std::
#define dbg(x) sd cout<<#x<<":"<<x<<" "
#define dg(x) sd cout<<#x<<":"<<x<<"\n"
#define inf 1e10
#define pii sd pair<int,int>
#define X first
#define Y second
int read(){int w=1,c=0;char ch=getchar();for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') w=-1;for(;ch>='0'&&ch<='9';ch=getchar()) c=(c<<3)+(c<<1)+ch-48;return w*c;}
void printt(int x){if(x>9) printt(x/10);putchar(x%10+48);}
void print(int x){if(x<0) putchar('-'),x=-x;printt(x);}
void printk(int x){print(x);putchar(' ');}
void put(int x){print(x);puts("");}
const int N=2e5+10,P=1e9+7;
int n,a[N][5];
void fre()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
sd vector<pii> v[5];
int ans;
int cmp(pii x,pii y)
{
	return x.X-x.Y<y.X-y.Y;
}
void solve()
{
	v[1].clear();v[2].clear();v[3].clear();
	ans=0;
	n=read();
	F(i,1,n)
	{
		F(j,1,3) a[i][j]=read();
		int ma=(a[i][1]>a[i][2]?1:2),cma=(a[i][1]>a[i][2]?2:1);
		if(a[i][3]>a[i][ma]) cma=ma,ma=3;
		else if(a[i][3]>a[i][cma]) cma=3;
		v[ma].emplace_back(a[i][ma],a[i][cma]);
		ans+=a[i][ma];
	}
	int k=n/2,now=0;
	F(i,1,3) if((int)v[i].size()>k) now=i;
	if(!now) return put(ans);
	sd sort(v[now].begin(),v[now].end(),cmp);
	k=v[now].size()-k;
	F(i,0,k-1) ans-=v[now][i].X-v[now][i].Y;
	put(ans);
}
int main()
{
	fre();
	int T=1;
	T=read();
	while(T--) solve();
}
/*
先把所有人都分配到价值最大的组里
不难发现最多有一个组有矛盾
现在即将这些人分配到其他组去
肯定是去次大的组别
贡献损失是最大减去次大
于是按照这个排序即可 

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


ans:

18
4
13

*/
