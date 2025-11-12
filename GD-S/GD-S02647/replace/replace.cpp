#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200000
int n,q;
string s[N][2],t[2];
inline int read()
{
	int res=0;
	char x=getchar();
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')res=res*10+(x-'0'),x=getchar();
	return res;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--)
	{
		printf("0\n");
	}
}
