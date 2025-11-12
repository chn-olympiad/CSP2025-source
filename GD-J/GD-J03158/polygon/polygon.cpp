#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<1;
		return 0;
	}else{
		int s=1;
		for(int i=n;i>=3;i--){
			s=s*i;
		}
		s/=6;
		cout<<s-1;
		
	}
	return 0;
} 
