#include <bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	re int x=0; re char c;
	while((c=getchar())<'0');
	do x=(x<<1)+(x<<3)+(c^48);
	while((c=getchar())>='0');
	return x;
}
inline void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10|48);
}
const int N=1e5+5;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	short T; scanf("%hd",&T);
	while(T--)
	{
		int n=read(),cntx,cnty,cntz,ans;
		const int lim=n>>1;
		cntx=cnty=cntz=ans=0;
		priority_queue<int,vector<int>,greater<int>> q1,q2,q3;
		for(re int i=0;i<n;++i)
		{
			int x=read(),y=read(),z=read(),
				mx1=max({x,y,z}),mx2;
			if(mx1==x) mx2=max(y,z);
			else if(mx1==y) mx2=max(z,x);
				 else mx2=max(x,y);
			if(x==mx1)
			{
				if(cntx==lim)
				{
					int tmp=q1.top(),
						val1=mx1-mx2,val2=tmp;
					if(val1>val2)
						ans+=mx1-tmp,q1.pop(),q1.emplace(val1);
					else ans+=mx2;
				}
				else ++cntx,ans+=mx1,q1.emplace(mx1-mx2);
			}
			else if(y==mx1)
				 {
					 if(cnty==lim)
					 {
						 int tmp=q2.top(),
							 val1=mx1-mx2,val2=tmp;
						 if(val1>val2)
							 ans+=mx1-tmp,q2.pop(),q2.emplace(val1);
						 else ans+=mx2;
					 }
					 else ++cnty,ans+=mx1,q2.emplace(mx1-mx2);
				 }
				 else
					 if(cntz==lim)
					 {
						 int tmp=q3.top(),
							 val1=mx1-mx2,val2=tmp;
						 if(val1>val2)
							 ans+=mx1-tmp,q3.pop(),q3.emplace(val1);
						 else ans+=mx2;
					 }
					 else ++cntz,ans+=mx1,q3.emplace(mx1-mx2);
		}
		write(ans),putchar(10);
	}
	return 0;
}
