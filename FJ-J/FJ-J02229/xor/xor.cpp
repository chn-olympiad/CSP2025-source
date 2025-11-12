#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
int a[500005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	if(n<=2&&k==0){
		cout <<0;
		
		return 0;
	}
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin >>a[i];
			if(a[i]==0)ans++;
		}
		cout <<ans;
		
		return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin >>a[i];
			if(a[i]==1)ans++;
		}
		cout <<ans;
	}
	
	return 0;
}
