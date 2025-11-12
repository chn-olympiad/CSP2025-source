#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,b=0;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		long long xo=0;
		for(int j=i;j<n;j++){
			xo^=a[j];
			if(xo==k){
				b++;
				i=j;
				break;
			}
		}
	}
	cout<<b;
	return 0;
}
