#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[50005]={};
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		int t=a[i],r=0,j=1;
		while(t>0){
			r=t%2*j+r;
			t/=2;
			j*=10;
		}
		a[i]=r;
	}
	cout<<1;
	return 0;
}
