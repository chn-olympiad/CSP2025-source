#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,a[1005],k,tmp,sum =0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		tmp = a[i];
		for(int ic=0;ic<n;ic++){
			if(tmp==k && ic>=i){
				sum++;
				i = ic+1;
				break;
			}
			tmp=tmp xor a[ic];
		}
		if(tmp==k){
			sum++;
			i = n; 
		}
	}
	cout<<sum;
}