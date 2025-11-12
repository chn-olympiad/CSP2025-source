#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001],sum;
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++){
			int idx=i*n+j;
			cin>>a[idx];
			if(a[idx]>=a[1])	sum++;
		}
	}
//	cout<<sum<<endl;
	int ans=ceil(sum*1.0/n);
	if(ans%2==0){
		cout<<ans<<" ";
		if(sum%n){
			cout<<1;
		}else{
			cout<<n-(sum%n)+1;
		}
	}else{
		cout<<ans<<" ";
		if(sum%n){
			cout<<sum%n;
		}else{
			cout<<n;
		}
	}
	
}
