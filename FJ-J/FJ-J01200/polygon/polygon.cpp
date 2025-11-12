#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[0]*2<a[0]+a[1]+a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		int fu=0;
		for(int i=3;i<n;i++){
			fu+=i;
		}
		cout<<fu;
	}
	return 0;
}
