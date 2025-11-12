#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	int k=3;
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int mx=a[n];
		if(sum>2*mx){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}