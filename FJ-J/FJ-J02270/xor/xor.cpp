#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}else{
				int sum=1;
				while(a[i]==a[i+1]){
					sum++;
					i++;
				}
				ans+=(sum/2);
			}
		}
	}
	cout << ans << endl;
}
