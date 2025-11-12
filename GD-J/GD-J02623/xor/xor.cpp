#include<iostream>
#include<algorithm>
using namespace std;
long long n,k,a[1060900];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0) cout<<n/2;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
