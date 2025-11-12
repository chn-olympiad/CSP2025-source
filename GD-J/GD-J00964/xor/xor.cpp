#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int f[500005];
int last[500005];
int qzh[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1]^a[i];
		int yh=0;
		for(int j=i;j>=1;j--){
			yh=max(yh,last[j]);
			if(j<=yh){
				break;
			}
			if((qzh[i]^qzh[j-1])==k){
				last[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(last[i]!=0){
			f[i]=max(f[i],f[last[i]-1]+1);
		}	
	}
	cout<<f[n];
}

