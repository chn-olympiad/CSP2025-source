#include<bits/stdc++.h>
#define file(NAME)\
	freopen(NAME".in","r",stdin);\
	freopen(NAME".out","w",stdout);
#define ll long long
#define rep(i,x,y) for(int i=x,y_=y;i<=y_;i++)
#define per(i,x,y) for(int i=y,x_=x;i>=x_;i--)
using namespace std;
const int N=505,M=0,S=2.7e5,NN=20,P=998244353;
int n,m,a[N],c[N],d,g;
string str;
ll z,s,f[S][NN];
void upd(ll &x,ll y) {x=(x+y)%P;}
int main()
{
	file("employ");
	cin>>n>>m>>str;
	rep(i,1,n) a[i]=str[i-1]-'0';
	rep(i,1,n) scanf("%d",&c[i]);
	if(n<=18)
	{
		int po[NN];
		po[0]=1;
		rep(i,1,n) po[i]=po[i-1]*2;
		memset(f,0,sizeof(f)),f[0][0]=1;
		rep(i,0,po[n]-2)
		{
			d=0;
			for(int i_=i;i_;d+=(i_&1),i_>>=1);
			rep(j,0,d)
			{
				rep(k,1,n)
				{
					if(i&po[k-1]) continue;
					if(j<c[k]&&a[d+1]==1) upd(f[i|po[k-1]][j],f[i][j]);
					else upd(f[i|po[k-1]][j+1],f[i][j]);
				}
			}
		}
		rep(i,0,n-m) z=(z+f[po[n]-1][i])%P;
		printf("%lld",z);
		return 0;
	}
	if(m==n)
	{
		rep(i,1,n) if(a[i]==0) {printf("0");return 0;}
		z=1;
		rep(i,1,n) z=z*i%P;
		printf("%lld",z);
		return 0;
	}
	if(m==1)
	{
		sort(c+1,c+n+1),d=0,z=1;
		rep(i,1,n)
		{
			while(d<n&&c[d+1]<i) d++,g++;
			if(a[i]) z=z*g%P,g--;
		}
		while(d<n) d++,g++;
		while(g) z=z*g%P,g--;
		s=1;
		rep(i,1,n) s=s*i%P;
		printf("%lld",(s-z+P)%P);
		return 0;
	}
	return 0;
}
