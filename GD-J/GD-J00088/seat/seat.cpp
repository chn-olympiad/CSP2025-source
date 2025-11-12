#include<bits/stdc++.h>
#define rd read()
#define int long long
using namespace std;
inline int read()
{
	int x=0,ss=1,s=getchar();
	while((s<'0'||s>'9')&&s!='-')s=getchar();
	if(s=='-')ss=-1,s=getchar();
	while(s>='0'&&s<='9')x=x*10+(s^48),s=getchar();
	return x*ss;
}
const int N=100005;
int n,m,R,rk,a[N];
inline bool cmp(int x,int y){return x>y;}
signed main()
{
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	n=rd,m=rd;
	for(int i=1;i<=n*m;++i)a[i]=rd;
	R=a[1],sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;++i)
	{
		if(a[i]==R){cout<<y<<' '<<x<<'\n';return 0;}
		if(y&1)x<n?++x:++y;
		else if(x>1)--x;
		else ++y;
	}
	return 0;
}
