#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i <= n;i++)
		cin>>a[i];
	if (k == 0){
		long long ans = 0;
		for (int i = 1;i <= n;i++)
			if (!a[i]) ans++;
		cout<<ans;
		return 0;
	}
	if (k == 1){
		long long ans = 0;
		for (int i = 1;i <= n;i++){
			if (a[i]) ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

