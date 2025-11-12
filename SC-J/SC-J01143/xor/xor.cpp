#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k,ans=0;
	cin>>n>>k;
	vector<int> A(n+1),B;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int r=j;
			int cnt=A[i];
			for(int l=i+1;l<=r;l++){
				cnt^=A[l];
			}
			B.push_back(cnt);
		}
	}
	if(B[0]==k) ans++;
	for(int i=1;i<B.size();i++){
		if(B[i-1]!=k && B[i]==k) ans++;
	}
	cout<<ans;
	return 0;
}
