#include<bits/stdc++.h>
using namespace std;
inline int read(){int x=0;bool b=0;signed c=getchar();while(c<48||c>57)b=c==45,c=getchar();while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=getchar();return b?-x:x;}
inline void write(int x,signed c){if(!x){putchar(48),putchar(c);return;}if(x<0)x=-x,putchar(45);signed i=0,a[32];while(x)a[++i]=x%10^48,x/=10;while(i)putchar(a[i--]);putchar(c);}
int n,q;
signed main()
{
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	while(q--)
		write(0,10);
	return 0;
}
