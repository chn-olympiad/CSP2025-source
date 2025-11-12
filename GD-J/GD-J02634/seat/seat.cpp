#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[105],rnum,cnt;

bool cmp(int aa,int bb){
	return aa>bb;
}

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	rnum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		bool flag=0;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[++cnt]==rnum){
					printf("%lld %lld",i,j);
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++cnt]==rnum){
					printf("%lld %lld",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
