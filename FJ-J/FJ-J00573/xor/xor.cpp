#include<bits/stdc++.h>
using namespace std;
int n,k,a[5010],s[5010],ans=0,ans2=0;
bool tmp=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]!=1){
			tmp=1;
		}
	}
	if (tmp==0){
		cout << n*(n+1)/2;
		return 0;
	}
	long long xr=a[1];
	for(int i=2;i<=n;i++){
		if (xr==k){
			ans2++;
			xr=a[i];
		}else{
			ans2^=a[i];
		}
	}
	if (xr==k) ans2++;
	cout << ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
