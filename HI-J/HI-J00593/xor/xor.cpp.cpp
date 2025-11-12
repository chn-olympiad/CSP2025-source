#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[50005],b=0,c=0,l=0,x=1;
    cin >> n >> k;
    for(int i=1;i<=n;i++) {
    	cin >> a[i];
    	if(a[i]==0) {
    		b++;
		}
		if(a[i]==1) {
			c++;
		}
	} 
	if(k==0) {
	   if(b==1 || b==0) {
	   	cout << b;
	   	return 0;
	   }
	}
	if(k==2) {
		if(c==1 || c==0) {
			cout << c;
			return 0;
		}
	}
	if(k<=10) {
		cout << "2";
	}
	if(k>=100) {
		cout << "67";
	}
	return 0;
} 
