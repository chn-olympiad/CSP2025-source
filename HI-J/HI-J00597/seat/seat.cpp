#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,a[100001],sum=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<n*m;i++){
		if(a[i]>a[0]) sum++;
	}
	if(n==1) cout<<sum<<" "<<1;
	if(m==1) cout<<1<<" "<<sum;
	if(n==2&&m==2){
		if(sum==1) cout<<1<<" "<<1;
		else if(sum==2) cout<<1<<" "<<2;
		else if(sum==3) cout<<2<<" "<<2;
		else cout<<2<<" "<<1;
	}
	return 0;
} 
