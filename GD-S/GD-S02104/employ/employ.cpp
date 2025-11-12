#include<bits/stdc++.h>
#define int long long
using namespace std;
//这么难的题不就是给我上迷惑行为大赏的吗
//注：ps是我的忠实粉丝
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	return 0;
}
