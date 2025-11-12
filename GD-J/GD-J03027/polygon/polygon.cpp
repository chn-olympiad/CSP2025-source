#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long sum;
int a[11000],b[11000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	if(b[n]>a[n]*2){
		sum++;
	}
	for(int i=1;i<=n-3;i++){
		for(int j=1;j<n-i+1;j++){
			cnt=b[n]-b[j+i-1]+b[j-1];
			if(cnt>a[n]*2){
				sum++;
				cout<<cnt;
			}
		}
		cnt=b[n-i];
		if(cnt>a[n-i]*2){
			sum++;
			cout<<cnt;
		}
	}
	cout<<sum%998244353;
	return 0;
}
