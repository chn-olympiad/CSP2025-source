#include <cstdio>
long long n,m,x,f,cnt=1,line=1;
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	scanf ("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			scanf ("%lld",&f);
			if (i==1&&j==1)
				x=f;
			if (f>x)
				cnt++;
		}
	while(cnt){
		if (cnt>n)
			cnt-=n,line++;
		else if (line&1)
			printf ("%lld %lld",line,cnt),cnt=0;
		else
			printf ("%lld %lld",line,n+1-cnt),cnt=0;
	}
	return 0;
}
