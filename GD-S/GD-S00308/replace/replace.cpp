#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int fg=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fg=-fg;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return fg*x;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return 0;
}
