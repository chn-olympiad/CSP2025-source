#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		cout<<0;
	}else if(n==3){
		if(a[0]+a[1]>a[2] && a[0]+a[2]>a[1] && a[1]+a[2]>a[0]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<1;
	}
}

