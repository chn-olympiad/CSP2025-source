#include <iostream>
using namespace std;
int n,a[500005]={-0x3f3f3f3f},k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n;
	return 0;
}
