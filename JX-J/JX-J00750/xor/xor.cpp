#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500000],b[5000000],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
