#include<bits/stdc++.h>
using namespace std;
int n,k,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1,u;i<=n;i++){
		u=a[i]+a[i+1];
		for(int j=i+2;j<=n;j++){
			u+=a[j];
			u=u%998244353;
			if(u>a[j]*2){
				k++;
				k=k%998244353;
			}
		}
	}
	printf("%d",k);
	return 0;
}
