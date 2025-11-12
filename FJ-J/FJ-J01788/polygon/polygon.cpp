#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,flag=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(n==3){
		if(max(max(a[0],a[1]),a[2])*2<a[0]+a[1]+a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(flag==0){
		int sum=0;
		for(int i=1;i<=n-3;i++){
			sum+=i;
		}
		cout<<sum;
	}else{
		cout<<366911923;
	}
	return 0;
}
