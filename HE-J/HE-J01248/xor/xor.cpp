#include <iostream>
#include <cstdio>
using namespace std;
const int N=5e5+5;
int n;
long long k,a[N],pre[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		f[i]=f[i-1];
		int j=i-1;
		while(j>=0&&f[j]==f[i]){
			if((pre[i]^pre[j])==k){
				f[i]=f[j]+1;
			}
			j-=1;
		}
	}
	cout<<f[n]<<endl;
	return 0;
}

