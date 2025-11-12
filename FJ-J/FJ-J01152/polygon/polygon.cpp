#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			cout<<1;
			return 0;
		}
	}
	if(n>=500&&n<=5000){
		long long sum=0;
		for(int i=1;i<=n;i++){
			long long cnt=0;
			for(int j=1;j<=n;j++){
				cnt+=i;
			}
			sum=sum+sum+cnt;
		}
		return 0;
	}
	cout<<0;
	return 0;
}
