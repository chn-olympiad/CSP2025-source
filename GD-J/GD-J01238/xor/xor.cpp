#include<bits/stdc++.h>
using namespace std;
//o表示上一个选中的区间的右端点 
long long n,k,ans,o,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	while(1){
		bool p=0;
		for(int i=1;i<=n-o;i++){
			for(int j=o+1;j-o<=i&&j<=n;j++){
				int l=j,r=o+i;
				if((a[r]^a[l-1])==k){
					o=r;
					p=1;
					ans++;
					break;
				}
			}
			if(p==1) break;
		}
		if(p==0) break;
	}
	cout<<ans;
	return 0;
} 
