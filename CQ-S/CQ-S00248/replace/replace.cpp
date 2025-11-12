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

/*
还有最后一分钟。
失败了，T2都错题导致浪费了一个多小时的时间。
noip记得好好读题。
确定一下文件读入读出
七级狗的愿望还是破掉了。估计一车人200上 
*/

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return 0;
}
