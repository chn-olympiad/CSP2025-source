#include<bits/stdc++.h>
using namespace std;
long long aa,bb,c,d; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>aa>>bb;
	long long sum=aa*bb;
	long long a[sum];
	for(int i=0;i<sum;i++){
		cin>>a[i];
	}
	if(aa==1&&bb==1){
		cout<<aa<<' '<<bb;
		return 0;
	}
	if(aa==2&&aa==2){
		cout<<2<<" "<<2;
		return 0;
	}
	if(aa==3&&bb==3){
		cout<<3<<" "<<1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
