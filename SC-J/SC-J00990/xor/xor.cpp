#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans = 0;
	cin>>n>>k;
	vector<int> A(n);
	for (int i = 0;i < n;i++){
		cin>>A[i];
	}
	int i = 0,j = 0;
	while(i < n && j < n){
		int z = 0;
		for (int l = i;l < j + 1;l++){
			z = (z ^ A[l]);
		}
		if (z == k){
			i = j + 1;
			j = i + 1;
			ans++;
		}else{
			j++;
		}
	}
	cout<<ans;
	return 0;
}