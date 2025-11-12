#include<bits/stdc++.h>
using namespace std;
int xr(int a,int b){
	bitset<32> aa(a),bb(b);
	long long c=0;
	for(int i=0;i<32;i++){
		if(aa[i]!=bb[i])c+=pow(2,i);
	} 
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int r[n];
	for(int i=0;i<n;i++){
		cin>>r[i];
	} 
	int sum=0;
	for(int i=0;i<n;i++){
		int d=r[i];
		if(d!=k){
			for(int j=i+1;j<n;j++){
				if(d==k){
					sum++;
					break;
				}
				else{
					d=xr(d,r[j]);
				}
			}
			if(d==k){
				sum++;
			}
		}
		else{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
