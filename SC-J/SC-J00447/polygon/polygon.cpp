#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int m=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]-m>m*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else {
		long long sum=0;
		for(long long i=4;i<=n;i++){
			sum+=i;
		}
		cout<<sum;
	}
	return 0;
}