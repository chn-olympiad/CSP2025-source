#include <bits/stdc++.h>
using namespace std;
int n,k,ans,flag,XOR;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){	
			XOR=a[i];
			if(XOR==k){
				ans++;
				continue;
			}else
			for(int j=i;j<n;j++){
				XOR^=a[j];
				if(XOR==k){
					i=j;
					ans++;
					break;
				}
			}
	}
	
	

	cout<<ans;//~15pts?
	return 0;
}

