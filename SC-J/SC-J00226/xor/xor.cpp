#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;cin>>n>>k;
	vector<int> A(n+1),B(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>A[i];
		B[i] = (B[i-1] ^ A[i]);
		//前缀异或和
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j>=1;j--){
			if((B[i] ^ B[j-1])==k){
				cnt++;
				i = j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}