#include<bits/stdc++.h>
using namespace std;
long long a[1000000],j,n,m,a1,jj=1,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a1){
			jj++;
		}
	}
	j=jj%(2*n);
	jj=(jj-1)/n;
	if(j>n) j=2*n-j+1;
	cout<<jj+1<<" "<<j; 
	fclose(stdin);
	fclose(stdout);
} 
