#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,a1,a[999],c=0,r=0;
	cin>>n>>m>>a1;
	int ranking=1;
	for(int i=0;i<n*m-1;i++){
		cin>>a[i];
	}
	for(int j=0;j<n*m-1;j++){
		if (a1<a[j])
			ranking++;
	}
	if (ranking==m*n+1)
		ranking=m*n;
		
	if (ranking<=n)
		c=1;
	else 
		c=ranking/n+1;
		
	int sum=ranking%(2*n);
	if (sum<=n){
		r=sum;
	}
	else	
		for(int i=n;i>sum-n;i--){
			r=i;
		}
	cout<<c<<" "<<r<<endl;
	return 0;
}
