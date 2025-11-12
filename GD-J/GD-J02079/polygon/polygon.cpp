#include<bits/stdc++.h>
using namespace std;
int a[5500];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}
	
	if(n==3){
		int maxn=0,sum=0;
		for(int i=1;i<=3;i++){
			maxn=max(maxn,a[i]);
			sum=sum+a[i];
		}
		maxn*=2;
		if(maxn<sum){
			cout<<1;
		}
		else{
			cout<<0;
		}
	} 
	
	return 0;
}
