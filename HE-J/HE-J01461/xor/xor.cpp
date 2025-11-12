#include<bits/stdc++.h>
using namespace std;
long long b[1000000];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		long long x;
		cin>>x;
		b[i]=b[i-1]^x;
	}
	long long l=0,q;
	bool s=1;
	for(int i=0; i<=n; i++) {
			if(s==0){
				i=q;
				s=1;
			}
			for(int j=i+1; j<=n; j++) {
				if((b[j]^b[i])==k) {
					l++; 
					q=j;
					s=0;
					break;
				}
			}

	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
