#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,a[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		int x=0,s=0;
		for(int j=i;j>=1;--j){
			s^=a[j];
			if(f[j-1]<f[i-1])break;
			if(s==k){
				x=j;
				break;
			}
		}
		if(x)f[i]=max(f[i-1],f[x-1]+1);
		else f[i]=f[i-1];
	}
	cout<<f[n]<<"\n";
	return 0;
}

