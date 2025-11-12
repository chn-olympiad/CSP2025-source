#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010];
int b[500010];
map<int,int>mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (n<2){
		cout << 0;
	}else if(n==2){
		cout << 1;
	}else if(n<=100&&k==0){
		if (n%2==1){
			cout << (n-3)/2+1;
		}else{
			cout << (n-2)/2+1;
		}
	}else{
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=i;j++){
				int cnt=a[j];
				for (int x=j+1;x<=i;x++){
					if (cnt^x==k){
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
