#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5001]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		int k=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>2*k){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
} 
