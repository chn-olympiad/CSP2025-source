#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],maxlen;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3){
		if(n<=2)return 0;
		sort(a+1,a+n+1);
		for(int i=1;i<n-1;i++){
			for(int j=2;j<n;j++){
				for(int k=3;k<=n;k++){
					if(a[k]*2<a[i]+a[j]+a[k]){
						maxlen=max(maxlen,a[k]);
					}
				}
			}
		}
		cout<<maxlen%1000000;		
	}
	else{
		maxlen=1;
		for(int i=1;i<=n;i++){
			maxlen*=i;
		}
		cout<<maxlen%100000000;
	}
	return 0;
}
