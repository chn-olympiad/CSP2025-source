#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;	
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*(max(a[1],max(a[2],a[3]))))cout<<1;
		else cout<<0;
		return 0;
	}
	int m=3;
	while(m<n){
		int k=-1;
		while(n-m-k>0){
			ans+=n-m-k;
			k++;
			
		}
		m++;
	}
	cout<<ans+1;
	return 0;
}


