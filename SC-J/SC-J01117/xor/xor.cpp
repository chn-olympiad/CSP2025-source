#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int A[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>A[i];
		if(k==0){
		int flg=1;
		for(int i=1;i<=n;i++){
			if(A[i]!=1){
				flg=0;
			}
		}
		if(flg==1) cout<<n;
	}
	return 0;
}
//^
