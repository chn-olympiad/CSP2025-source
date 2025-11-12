#include<bits/stdc++.h>
using namespace std;
long long n,k,sum;
long long a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sum = a[1];
	if(n==2){
		if(a[1]<a[2]) sum = a[2];
	} 
	if(n==4){
		if(sum<a[2]^a[3]^a[4]) sum = a[2]^a[3]^a[4];
	}
	if(n==3){
		if(sum<a[2]^a[3]) sum = a[2]^a[3];
	}
	cout<<sum;
	return 0;
}
