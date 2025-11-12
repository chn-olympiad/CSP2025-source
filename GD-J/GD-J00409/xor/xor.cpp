#include<iostream>
using namespace std;
int xrs[500005],f[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		xrs[i]=xrs[i-1]^x;
	}
	int ltp=0;
	for(int i=1;i<=n;i++){
		int j;
		for(j=i-1;j>=ltp;j--)if((xrs[i]^xrs[j])==k)break;
		if(j==ltp-1)f[i]=f[i-1];
		else{
			f[i]=f[j]+1;
			ltp=i;
		}
	}
	cout<<f[n];
	return 0;
}
