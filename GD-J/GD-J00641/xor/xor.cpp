#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005],s[100005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1]+a[i];
	}
	if(k==1){
		cout << s[n];
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1 && a[i+1]==1){
				ans++;
				i++;
			}
			if(a[i]==0){
				ans++;
			}
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
