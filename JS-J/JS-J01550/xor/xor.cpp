#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,tgt;
	cin >>n>>tgt;
	int a[n] = {0};
	bool m[n] = {false};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int l=0;l<n+1;l++){
		for(int i=0;i<n-l+1;i++){
			int sum = 0;
			bool success = true;
			for(int j=i;j<l+i;++j){
				if(m[j]==true){
					success = false;
					break;
				}
				sum ^= a[j];
			}
			if(sum == tgt and success){
				for(int j=i;j<l+i;j++){
					m[j] = true;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
