#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,k,a[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		if(a[i]==k){
			cnt++;
			a[i]=0;
		}
	}
	cout<<cnt;
	return 0;
}
