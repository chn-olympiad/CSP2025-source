#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10;
const int INF=0x3f3f3f3f;
const int mod=998244353;
inline int read()
{
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') num=num*10+c-'0',c=getchar();
	return num*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10),x%=10;
	putchar(x+'0');
}
int n,m,ans=1;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
	return 0;
}
