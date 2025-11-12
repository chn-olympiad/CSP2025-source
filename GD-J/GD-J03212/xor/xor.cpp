#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,c=0,k,o=0;
	cin>>n>>k;
	int a[n];
	for(long long i=0;i<n;i++) {
		cin>>a[i];
		if(a[i]>=1) c++;
		else o++;
	}
	if(k==0) cout<<o;
	else cout<<c-k+1;
		return 0;
	fclose(stdin);
	fclose(stdout);
}
