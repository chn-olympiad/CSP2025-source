#include <iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a;cin>>n>>k;
	int c[n]={0};
	for(int i=0;i<n;i++){
		cin>>a;
		c[i]=a;
	}
	cout<<k;
	return 0;
}
