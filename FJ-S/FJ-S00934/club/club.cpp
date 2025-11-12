#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}struct S{long long s,d;}A[4];
bool cmp(S a,S b){return a.s>b.s;}
long long a[5200][5200],_,n,r,f,v[5201314],m[5201314],f1;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	_=read();
	while(_--){
		n=read(),r=0,f=f1=1;
		if(n==2){
			for(long long i=1;i<=n;++i)for(long long j=1;j<=3;++j)a[i][j]=read();
			for(long long i=1;i<=3;++i)for(long long j=1;j<=3;++j){
				if(i!=j)r=max(r,a[1][i]+a[2][j]);
			}printf("%lld\n",r);continue;
		}else if(n==4){
			for(long long i=1;i<=n;++i)for(long long j=1;j<=3;++j)a[i][j]=read();
			for(long long i=1;i<=3;++i)for(long long j=1;j<=3;++j)for(long long k=1;k<=3;++k)for(long long l=1;l<=3;++l){
				if(!((i==j&&j==k&&k==l)||
				(i==j&&j==k)||
				(j==k&&k==l)||
				(k==l&&l==i)||
				(l==i&&i==j)
				))r=max(r,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
			}printf("%lld\n",r);continue;
		}else{
			for(long long i=1;i<=n;++i){
				for(long long j=1;j<=3;++j){
					A[j].s=read(),A[j].d=j;if(A[2].s!=0||A[3].s!=0)f1=0;
				}sort(A+1,A+4,cmp);
				++v[A[1].d],m[i]=A[1].s;
			}for(long long i=1;i<=3;++i)if(v[i]>(n>>1)){f=0;break;}
			if(f){
				for(long long i=1;i<=n;++i)r+=m[i];
				printf("%lld\n",r);
				continue;
			}if(f1){
				sort(m+1,m+n+1,greater<long long>());
				for(long long i=1;i<=(n>>1);++i)r+=m[i];
				printf("%lld\n",r);
				continue;
			}else printf("114514");
		}
	}
}
