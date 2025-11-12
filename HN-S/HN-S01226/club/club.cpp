/*
ygg plz!
luogu 1058570(the person who fought with kkksc03.lol)
plz 350+.

(14:15)sui_sui_nian before csp start:
i asked(in luogu) how to use Chinese in dev-c++,but almost everyone told me to speak English.
well my English is better than Chinese(i got English 98pts and Chinese 93.5pts).LOL
you(who is doing mi_huo_xing_wei_da_shang) can check my grammar.
ok let this be T1 code.
(14:24)waiting...
the all things i lost,i keeped,i loved,will be ALL BACK.
WHY DOES EVERYONE PLAYING xiao_kong_long?fake.

(14:30)started.
wtf is t1?

(14:52)checked 4 statement.
then wtf is t1?

oh there will be at most 1 will be banned.
meiju 1,2,3?

solved B.
1 n/2,2 n/2,let a2<-a2-a1,sort it.

so let a1=0,a2=a2-a1,a3=a3-a1:
sort with cmp(max(a2,a3)>max(b2,b3));
might be right.
plz.

WTF 1 HOUR GOES??!
WA ON PRETEST2.noooooooooooooooooo

OK FIXED.

woc,1h and 30min(15:57)solve A,tuiyile.

anyway next.ygg plz!
*/
#include<bits/stdc++.h>
using namespace std;
inline int read()
	{
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
	}//int x=read();
int n,anss=0;
struct node{int a,b,c,tag;}a[100005],b[100005];
int cmp(node x,node y){return max(x.a,x.b)>max(y.a,y.b);}
int cmp2(node x,node y){return x.a-max(0,x.b)>y.a-max(0,y.b);}
inline void solve()
	{
	int ans=0;
	for(int i=1;i<=n;i++)a[i].a-=a[i].c,a[i].b-=a[i].c,ans+=a[i].c;
	sort(a+1,a+n+1,cmp);
	int now;
	for(int i=n;i;i--)
		{
		if(max(a[i].a,a[i].b)>=0||i<=n/2){now=i;break;}
		a[i].tag=1;
		}
	sort(a+1,a+n+1,cmp2);
	int cnta=n-now,cntb=0,cntc=0;
	for(int i=1;i<=n;i++)
		{
		if(a[i].tag)continue;
		int b=a[i].a,c=a[i].b;
		if(b>c)
			{
			if(cntb<n/2){ans+=b;cntb++;}
			else if(c>=0||cnta==n/2){ans+=c;cntc++;}
			else cnta++;
			}
		else
			{
			if(cntc<n/2){ans+=c;cntc++;}
			else if(b>=0||cnta==n/2){ans+=b;cntb++;}
			else cnta++;
			}
		//cout<<b<<' '<<c<<'\n';
		}
	anss=max(anss,ans);
	return;
	}
inline void sol()
	{
	n=read();anss=0;
	for(int i=1;i<=n;i++)
		{
		b[i].a=read();b[i].b=read();b[i].c=read();b[i].tag=0;
		}
	for(int i=1;i<=n;i++)a[i].a=b[i].a,a[i].b=b[i].b,a[i].c=b[i].c,a[i].tag=0;
	solve();
	for(int i=1;i<=n;i++)a[i].a=b[i].a,a[i].b=b[i].c,a[i].c=b[i].b,a[i].tag=0;
	solve();
	for(int i=1;i<=n;i++)a[i].a=b[i].b,a[i].b=b[i].a,a[i].c=b[i].c,a[i].tag=0;
	solve();
	for(int i=1;i<=n;i++)a[i].a=b[i].b,a[i].b=b[i].c,a[i].c=b[i].a,a[i].tag=0;
	solve();
	for(int i=1;i<=n;i++)a[i].a=b[i].c,a[i].b=b[i].a,a[i].c=b[i].b,a[i].tag=0;
	solve();
	for(int i=1;i<=n;i++)a[i].a=b[i].c,a[i].b=b[i].b,a[i].c=b[i].a,a[i].tag=0;
	solve();
	cout<<anss<<'\n';
	return;
	}
signed main()
	{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=read();
	while(t--)sol();
	return 0;
	}

