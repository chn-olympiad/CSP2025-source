#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL NM=200,N=20;
LL n,m,a[NM],s[N][N],p,l;
bool fx=0;	//0--xia 1 shang
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%lld",&a[1]);p=a[1];
	for(LL i=2;i<=n*m;i++)	scanf("%lld",&a[i]);
	sort(a+1,a+n*m+1,greater<LL>());
	if(n==1&&m==1)	puts("0 0");
	else{
		for(LL i=1;i<=n*m;i+=n){
			l++;
			if(fx==0)
				for(LL j=1;j<=n;j++){
					s[j][l]=a[i+j-1];
				//	cout<<s[j][l]<<' ';
				}
			else
				for(LL j=n;j>=1;j--){
					s[j][l]=a[i+n-j];
				//	cout<<s[j][l]<<' ';
				}
			//puts("");
			fx=!fx;
		}
		//puts("");
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=m;j++){
				//cout<<s[i][j]<<' ';
				if(s[i][j]==p){
					printf("%lld %lld",j,i);
					return 0;
				}
			}
			//puts("");
		}
	}
	return 0;
}
