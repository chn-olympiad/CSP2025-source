#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		int sum=0;
		long long maxa=-1;
		for(int i=1;i<=n;i++){
			sum+=a[i];	
			maxa=max(maxa,a[i]);
		}
		cout<<sum<<' '<<maxa<<endl;
		if(sum>maxa*2) cout<<1;
		else cout<<0;
	}
	else{
		long long maxa;
		for(int i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
		int sum=0,cnt=1;
		if(maxa<=1){
			for(int i=3;i<=n;i++){
				for(int j=1;j<=i;j++){
					cnt=cnt*(n+1-j)/j;
				}
				cout<<cnt<<endl;
				sum+=cnt;
				cnt=1;
			}
		}
		cout<<sum;
	}
	return 0;
}
