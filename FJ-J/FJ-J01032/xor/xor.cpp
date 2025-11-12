#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2,M=1<<20;
int n,k,a[N],f[N],d[M+2],sum,t=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		d[sum^k]=i;
		sum^=a[i];
		if(f[d[sum]]+1>f[i]&&d[sum]>t){
			f[i]=f[d[sum]]+1,sum=0;
			t=i;
		}
	}
	cout<<f[n];
	return 0;
}

