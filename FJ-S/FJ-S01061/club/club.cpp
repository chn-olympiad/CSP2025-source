#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){ll x=0,f=1;char c=getchar();while(c<48 || c>57){if(c=='-'){f=-1;}c=getchar();}while(c>=48 && c<=57){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return x*f;}
void write(ll x){if(x<0){x=-x;putchar('-');}if(x>9){write(x/10);}putchar((x%10)^48);}
/*

有n个人(n为偶数) n<=1e5
共有3个部门
一个部门不能分配多于n/2个人
每个人对每个部门有a贡献 a<=2e4
求权值最大值

贪心? 优先安排最大的
a:12 9 7
b:12 6 6
c:7 7 7
d:10 2 4

A:-16 -12 -14 -6
B:-19 -18 -14 -14
C:-21 -18 -14 -12

A:a b 
B:c
C:d
12+12+7+4=35

A:b d
B:a
C:c
12+10+9+7=38
错误

分析样例
a:4 2 1 
b:3 2 4
c:5 3 4
d:3 5 1

A:a c
B:d
C:b
4+4+5+5=18

a:0 1 0 
b:0 1 0
c:0 2 0
d:0 2 0

把每个人的贡献累加 
遍历一遍 背包 如果放在A部门则B和C部门中减去他
判断最大人数的部门人数是否大于n/2
a:4 2 1 
b:3 2 4
c:5 3 4
d:3 5 1

A:4+3+5+3=15
B:2+2+3+5=12
C:1+4+4+1=10
T:15+12+10=37
  a        b        c        d
A -3 1 0 0 -6 1 0 0 -7 1 0 0 -6 1 0 0
B -5 0 1 0 -7 0 1 0 -9 0 1 0 -4 0 1 0
C -6 0 0 1 -5 0 0 1 -8 0 0 1 -8 0 0 1
选择扣的最少的先 
4 2 1 
3 2 4
5 3 4
3 5 1

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
const ll N=1e5+10;
ll T,n,a[N][4],cnt[4],ans;
struct point{
	ll x,j;//x为数值　j为加入的部门 
	friend bool operator < (point tmp1,point tmp2){return tmp1.x>tmp2.x;}
}f[N][4];
struct node{
	ll x,i,j;//x为数值　i为第几个人　j为f中的第几个 
	friend bool operator < (node tmp1,node tmp2){return tmp1.x<tmp2.x || (tmp1.x==tmp2.x && a[tmp1.i][ f[tmp1.i][tmp1.j].j ]<a[tmp2.i][ f[tmp2.i][tmp2.j].j ]);}
};
priority_queue<node> q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		ans=0;
		memset(cnt,0,sizeof cnt);
		for(ll i=1;i<=n;++i)
		{
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			for(ll j=1;j<=3;++j)
			{
				ans+=a[i][j];
				f[i][j].x=0;
				f[i][j].j=j;
				for(ll k=1;k<=3;++k) f[i][j].x-=(k==j?0:a[i][k]);
			}
//			for(ll j=1;j<=3;++j) cout<<f[i][j].x<<' ';
//			cout<<endl;
			sort(&f[i][1],&f[i][1]+3);
			q.push({f[i][1].x,i,1});
		}
//		cout<<"T:"<<ans<<endl;
		while(!q.empty())
		{
			node now=q.top();
			q.pop();
//			cout<<"T:"<<now.i<<' '<<now.j<<endl;
//			cout<<"T:"<<cnt[ f[now.i][now.j].j ]<<endl;
			while(cnt[ f[now.i][now.j].j ] == (n>>1))
			{
//				cout<<"TEST"<<endl;
				ll tmp1=now.j,tmp2=-0x3f3f3f3f;
				for(ll j=1;j<=3;++j)
				{
					if(f[now.i][j].x>tmp2 && j!=now.j && cnt[ f[now.i][j].j ] < (n>>1)) tmp1=j,tmp2=f[now.i][j].x;
				}
				q.push({f[now.i][tmp1].x,now.i,tmp1});
				now=q.top();
				q.pop();
			}
			cnt[ f[now.i][now.j].j ]++;
			ans+=f[now.i][now.j].x;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
