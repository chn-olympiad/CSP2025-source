#include <bits/stdc++.h>
using namespace std;
long long n,k,a[600000],b[600000],q=1;
unordered_map<long long,long long>p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	p[0]=1;
	for(long long i=1;i<=n;i++){
		if(p[(long long)(k^b[i])]==q){
			q++;
		}
		p[b[i]]=q;
	//	cout<<i<<' '<<q<<' '<<(k^b[i])<<' '<<b[i]<<'\n';
	}
	cout<<q-1;
	return 0;
}
