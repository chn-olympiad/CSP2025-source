#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int b[N];
int c[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(a[i]^b[i-1]);
	}
	for (int i=k;i<=n;i++){
		c[i-k+1]=(b[i]^b[i-k]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
