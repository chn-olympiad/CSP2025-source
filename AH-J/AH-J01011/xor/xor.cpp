#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[1]+a[2];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
