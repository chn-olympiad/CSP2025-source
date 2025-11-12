#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100010][5],d[5][100010],cnt,c1,c2,c3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(d,0X3f,sizeof(d));
		cnt=c1=c2=c3=0;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++) for(long long j=1;j<=3;j++) scanf("%lld",&a[i][j]);
		for(long long i=1;i<=n;i++){
			long long ms=max(a[i][1],max(a[i][2],a[i][3]));
			cnt+=ms;
			if(ms==a[i][1]){
				c1++;
				if(a[i][2]>a[i][3]) d[1][i]=ms-a[i][2];
				else d[1][i]=ms-a[i][3];
			}else if(ms==a[i][2]){
				c2++;
				if(a[i][1]>a[i][3]) d[2][i]=ms-a[i][1];
				else d[2][i]=ms-a[i][3];
			}else{
				c3++;
				if(a[i][1]>a[i][2]) d[3][i]=ms-a[i][1];
				else d[3][i]=ms-a[i][2];
			}
		}
		if(c1>n/2){
			sort(d[1]+1,d[1]+n+1);
			for(long long i=1;i<=c1-n/2;i++) cnt-=d[1][i];
		}
		if(c2>n/2){
			sort(d[2]+1,d[2]+n+1);
			for(long long i=1;i<=c2-n/2;i++) cnt-=d[2][i];
		}
		if(c3>n/2){
			sort(d[3]+1,d[3]+n+1);
			for(long long i=1;i<=c3-n/2;i++) cnt-=d[3][i];
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
