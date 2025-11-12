#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[105],mapn[105][105],seat=0,cnt=0;
bool cmp(const ll &a,const ll &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<(n*m);i++){
		scanf("%lld",&a[i]);
	}
	seat=a[0];
	sort(a,a+(n*m),cmp);
	for(ll i=0;i<m;i++){
		if((i+1)%2!=0){
			for(ll j=0;j<n;j++){
				mapn[j][i]=a[cnt];
				cnt++;
			}
		}
		else{
			for(ll j=n-1;j>=0;j--){
				mapn[j][i]=a[cnt];
				cnt++;
			}
		}
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(mapn[i][j]==seat){
				ll s=j+1,k=i+1;
				printf("%lld %lld",s,k);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
