#include<bits/stdc++.h>
using namespace std;
int a[200001], n, k, b[200001], ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin >> n >> k;
	for(int i = 1; i <= n; i++)
	cin >> a[i];
	if(k==0){
		for(int i = 1; i <= n; i++){
			if(a[i]==0&&b[i]==0){
				ans++;
				b[i] = 1;
			}
		}
		for(int i = 1; i < n; i++){
			if(a[i]==a[i+1]&&b[i]==0&&b[i+1]==0){
				ans++;
				b[i] = 1, b[i+1] = 1;
			}
		}
	}
	if(k==1){
		for(int i = 1; i <= n; i++){
			if(a[i]==1&&b[i]==0){
				ans++;
				b[i] = 1;
			}
		}
		for(int i = 1; i < n; i++){
			if(a[i]==a[i+1]+1&&b[i]==0&&b[i+1]==0&&((a[i]>a[i+1]&&a[i+1]%2==0)||(a[i]<a[i+1]&&a[i]%2==0))){
				ans++;
				b[i] = 1, b[i+1] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}