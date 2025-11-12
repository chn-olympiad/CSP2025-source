#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c=0,b=0;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			c++;
		}
	}
	for(int j=0;j<n;j++){
		for(int i=j;i<n;i++){
			b+=a[i];
			if(a[i]==0){
				b=-b;
			}
			if(a[i]==k){
				b=0;
			}
			if(b==k){
				c++;
				break;
				j=i;
			}
		}
	}
	cout << c;
	return 0;
}
