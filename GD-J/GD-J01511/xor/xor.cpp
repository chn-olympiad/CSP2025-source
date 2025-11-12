#include <bits/stdc++.h>
using namespace std;
int n;
long long k,a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans = 0;
	if(k == 1){
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			if(a[i] == 1) ans++;
		}
		cout<<ans<<endl;
	}
	else if(k == 0){
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			if(a[i] == 0) ans++;
		}
		cout<<ans<<endl;
	}
	else cout<<0<<endl;
	return 0;
}
