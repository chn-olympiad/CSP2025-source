#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r,sum=1;
	cin>>r;
	for(int i=1;i<n*m;i++){
		int t;
		cin>>t;
		if(t>r) sum++;
	} 
	int t=ceil(1.0*sum/n);
	cout<<t<<" ";
	if(t%2){
		if(sum%n==0) cout<<n;
		else cout<<sum%n;
	}else{
		if(sum%n==0) cout<<1;
		else cout<<n-sum%n+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
