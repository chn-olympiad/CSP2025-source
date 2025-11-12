#include<bits/stdc++.h>
using namespace std;
long long a[10000001],sum[100000001],ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	sum[1]=a[1];
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int len=3;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(sum[j]-sum[i-1]>a[j]*2)ans++;
		}
	}
	cout<<ans;
	return 0;
}
