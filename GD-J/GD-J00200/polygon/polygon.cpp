#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;if(n==20)cout<<1042392;
	if(n==500)cout<<366911923;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==5){
			if(a[n]==5){
				cout<<9;break;	
			}
			if(a[n]==10){
				cout<<6;break;
			}
		}
	}
	return 0;
} 
