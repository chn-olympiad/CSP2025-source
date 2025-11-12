#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL n;
LL a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++) cin>>a[i];
	LL cnt=0;
	for(LL i=1;i<=n;i++){
		for(LL j=i+1;j<=n;j++){
			for(LL k=j+1;k<=n;k++){
				if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[k]+a[j]>a[i]) cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
