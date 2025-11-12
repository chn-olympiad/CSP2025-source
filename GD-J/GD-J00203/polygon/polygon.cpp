#include<bits/stdc++.h>
using namespace std;
int n,a[91],num;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		cout<<0;
	}else if(n==3){
		num=max(a[1],a[2]);
		num=max(num,a[3]);
		if((a[1]+a[2]+a[3])>(2*num)){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
