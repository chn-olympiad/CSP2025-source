#include<bits/stdc++.h>
using namespace std;
int t,n,a[100100],b[100100],c[100100],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("clube.out","w",stdout);
	cin >> t;
	while(t--){
		ans=0;
		cin >> n;
		for(int i=1;i<=n;++i){
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a+1,a+n+1);
		for(int i=n;i>=n/2+1;--i){
			ans=ans+a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
