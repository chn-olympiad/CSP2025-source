#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N];
int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon1.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&n==2){
		cout<<0;
	}else if(n==3){
		int sum=0,cnm=0;
		for(int i=1;i<=3;i++){
			sum=max(sum,a[i]);
			cnm+=a[i];
		}
		if(sum*2<cnm){
			cout<<1;
		}else{
			cout<<0;
		} 
	}
	return 0;
} 
