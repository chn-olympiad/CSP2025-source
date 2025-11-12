#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s,k;
int a[105];
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%lld",&a[i]);
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++)
				if(a[++k]==s){
					printf("%lld %lld",j,i);
					return 0;
				}
		}
		else{
			for(int i=n;i>=1;i--)
				if(a[++k]==s){
					printf("%lld %lld",j,i);
					return 0;
				}
		}
	}
	return 0;
} 
