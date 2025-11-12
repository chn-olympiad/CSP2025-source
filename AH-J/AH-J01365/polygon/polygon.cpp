#include<bits/stdc++.h>
using namespace std;

int n,a[5500],d,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=2;j<n;j++){
			d=max(max(a[i],a[i-1]),a[j]);
			if(d==a[i]){
				if((a[i-1]+a[j]+a[i])>=2*d) sum++;
			}else if(d==a[i-1]){
				if((a[i]+a[j]+a[i-1])>=2*d) sum++;
			}else if(d==a[j]){
				if((a[i-1]+a[i]+a[j])>=2*d) sum++;
			}
		}
	}
	cout << sum%998244353;
	return 0;
}
