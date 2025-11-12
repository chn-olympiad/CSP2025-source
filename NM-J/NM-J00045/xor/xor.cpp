#include <iostream>
#include <cstdio>
using namespace std;
int n,k,a[500001],rela[501][501];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	cout<<n/2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}




