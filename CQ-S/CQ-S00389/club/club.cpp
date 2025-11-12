#include<bits/stdc++.h>
using std::min;
using std::max;
using std::pair;
#define int long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define edl putchar('\n')
#define lp first
#define rp second
#define lowbit ((x)&(-(x)))
const int inf=0x3f3f3f3f3f3f3f3f;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f*x;
}
void write(int x)
{
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void print(int x,char ed='\n'){write(x);putchar(ed);}
const int N=1e5+100,P=1e9+7;
int n;
std::priority_queue<int> pq[4];
void solve()
{
	n=read();
	for(int j=1;j<=3;j++) while(pq[j].size()) pq[j].pop();
	int ans=0; 
	for(int i=1;i<=n;i++)
	{
		int a1=read(),a2=read(),a3=read();
		if(a1>=max(a2,a3))
		{
			pq[1].push(max(a2,a3)-a1);
			ans+=a1;
		}
		else if(a2>=max(a1,a3))
		{
			pq[2].push(max(a1,a3)-a2);
			ans+=a2;
		}
		else
		{
			pq[3].push(max(a1,a2)-a3);
			ans+=a3;
		}
	}
	while((int)pq[1].size()>n/2) ans+=pq[1].top(),pq[1].pop();
	while((int)pq[2].size()>n/2) ans+=pq[2].top(),pq[2].pop();
	while((int)pq[3].size()>n/2) ans+=pq[3].top(),pq[3].pop();
	print(ans);
}
signed main()
{
//	system("fc club.out club.ans");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int T=read();T--;) solve();
	return 0;
}
//passed all of the examples at 14:42
