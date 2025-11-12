#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[100001]={},d[100001]={},n,k,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=(d[i-1]^a[i]);
	}
	int l=1,r=1;
	while(l<=n&&r<=n){
		int he=(d[r]^d[l-1]);
		if(he==k){
			sum++;
			l=r+1;
			r++;
		}else if(he<k){
			r++;
		}else{
			if(l<r){
				l++;
			}else{
				r++;
			}
			
		}
	}
	cout<<sum;
	return 0;
} 
