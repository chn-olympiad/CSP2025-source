#include<bits/stdc++.h>//luogu uid:956129
//#define int long long 
using namespace std;

namespace io
{
	inline int read(){int x=0,w=0;char c=0;while(!isdigit(c))w|=c=='-',c=getchar();while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();return w?-x:x;}
	template<typename T>void write(T x){if(x<0)x=-x,putchar('-');if(x>9)write(x/10);putchar(x%10+'0');}
	template<typename T>void write_(T x){write(x),putchar(' ');}
	template<typename T>void writeln(T x){write(x),putchar('\n');}
}
using namespace io;

const int N=5e2+10,M=998244353;
int n,m,p[N];
char c[N];

namespace subA
{
	void main()
	{
		int fl=0,sum=0;
		for(int i=1;i<=n;i++) fl|=(p[i]!=1);
		if(fl) return;
		for(int i=1;i<=n;i++) sum+=c[i]=='0';
		if(sum<m) writeln(0),exit(0);
		int ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%M;
		writeln(ans);
		exit(0);
	}
}

namespace subB
{
	void main()
	{
		
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",c+1);
	for(int i=1;i<=n;i++) p[i]=read();
	subA::main();subB::main();
	return 0;
}
