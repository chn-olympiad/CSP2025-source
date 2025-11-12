#include <iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio();
	{
	long long n,k;
		cin>>n>>k;
		int a[n+3];
		int maxn=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2) a[i]=a[i] xor a[i-1];
			cout<<a[i];
		}
		
		
	}
	return 0;
}