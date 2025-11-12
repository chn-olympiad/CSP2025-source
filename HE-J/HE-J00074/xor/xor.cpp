#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500010],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++) cin >>a[i];
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]) ans++;
		}
		cout <<ans;
	}else{
		for(int i=1;i<=n;i++){
			if(!a[i]) ans++;
		}
		for(int i=1;i+1<=n;i+=2){
			if(a[i]&&a[i+1]) ans++;
		}
		cout <<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
