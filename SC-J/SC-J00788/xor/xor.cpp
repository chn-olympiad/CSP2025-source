#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],b[500005],c[500005],cnt=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	for(int i=1; i<=n; ++i) {
		b[i]=a[i];
		if(b[i]==k){
			++cnt;
			++c[i];
			continue;
		}
		
	//	cout<<b[i]<<' ';
		for(int j=i+1;j<=n;++j){
			b[j]=b[j-1]^a[j];
			if(b[j]==k){
				++cnt;
				break;
			}
		//	cout<<b[j]<<' ';
		}
	//	cout<<'\n';
	}
	cout<<cnt;
	return 0;
}