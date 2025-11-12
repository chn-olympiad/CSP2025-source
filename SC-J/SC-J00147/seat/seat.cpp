#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[205],n,m,num,lie,hang;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	a[0]=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==a[0]){
			num=n*m-i+1;
			lie=num/n;
			num%=n;
			if(lie%2==1){
				if(num==0){
					hang=m;
				}else{
					lie++;
					hang=m-num+1;
				}
			}else{
				if(num==0){
					hang=1;
				}else{
					lie++;
					hang=num;
				}
			}
			break;
		}
	}
	cout<<lie<<' '<<hang;
	return 0;
}