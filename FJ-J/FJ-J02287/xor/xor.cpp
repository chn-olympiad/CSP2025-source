#include<bits/stdc++.h>
using namespace std;
int e(int x,int y){
	if(x==y){
		return 0;
	}
	else{
		return 1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[55555],sum=0;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		if(a[i]==k){
			sum++;
		}
	}
	cout<<sum;
}
