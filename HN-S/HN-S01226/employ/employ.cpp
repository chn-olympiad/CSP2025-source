/*
ygg plz!
luogu 1058570(the person who fought with kkksc03.)
plz 350+.

ok let this be t4 code.
oh t4 is counting!!!!!!!!!!!!
it is the last hope.ygg plz!
n,m=500?t=1?
anyway go to t1.

is A (n!)?
try it.

no??lol

wtf c can be 0?
difficult.

anyway go t2.

(17:46)i comes!
is it 01dp?
try to get 20.

is my csp good?100+72+25+20=217.
this is my best.
so why t2 tulun.
fake.
can 217 7gou?
idk.in the one hand the problems are harder(maybe not?),in the other hand competitors are all >12.
plz.let me NOT AFO.

(18:16)woc WA for 30min???
i solved it!!!!!!!!!!!

this is all i can do.
the best performance i did.
it is unimportant if i AFO or not.i did the best.
everytime,everytime i got -50 or higher as accident,but this time i did it.
i got the most pts as i can!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

i think i might be AFO.
Thanks:
cmozer,ysuperman,puck,all classmates in 7,and my npy.(lol)
thank you for giving me power,spirit,and darement(?if someone can translate) to fight with the life.
this is the last dance i did.
wish you remember me forever.
wish you forget me forever.
it's time to say goodbye.
goodbye,OI.
goodbye,everyone.
(18:25)
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
	{
	int x=0,f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
	}//int x=read();
const int p=998244353;
int n,m,a[1145],c[1145],dp[1<<19][20];
inline void sol()
	{
	cin>>n>>m;string S;cin>>S;
	for(int i=0;i<n;i++)a[i+1]=S[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int j=0;j<n;j++)
		{
		if(a[1]==0||c[j+1]==0)dp[(1<<j)][1]=1;
		else dp[(1<<j)][0]=1;
		}
	for(int s=1;s<(1<<n);s++)
		{
		for(int i=0;i<=n;i++)
			{
			//cout<<s<<' '<<i<<' '<<dp[s][i]<<'\n';
			int cnt=n;
			for(int j=0;j<n;j++)
				{
				if(s&(1<<j))continue;
				cnt--;
				}
			for(int j=0;j<n;j++)
				{
				if(s&(1<<j))continue;
				//cout<<"chk:"<<j+1<<' '<<c[j+1]<<' '<<cnt+1<<' '<<a[cnt+1]<<'\n';
				if(c[j+1]<=i||a[cnt+1]==0){dp[s|(1<<j)][i+1]=(dp[s|(1<<j)][i+1]+dp[s][i])%p;}//cout<<(s|(1<<j))<<' '<<i+1<<'\n';}
				else dp[s|(1<<j)][i]=(dp[s|(1<<j)][i]+dp[s][i])%p;
				}
			}
		}
	int ans=0;
	for(int i=0;i<=n-m;i++)ans=(ans+dp[(1<<n)-1][i])%p;
	cout<<ans;
	return;
	}
signed main()
	{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;
	while(t--)sol();
	return 0;
	}

