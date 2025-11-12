#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1001],b[1001],an;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[0]=a[1];
	for(int i=1;i<n;i++){
		b[i]=b[i-1]^a[i+1];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if((b[j]^b[i-1])==k){
				an++;
				
			}
		}
	}
	cout<<an;
	return 0;
}

