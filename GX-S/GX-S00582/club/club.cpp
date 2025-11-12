#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n,maxn,ans;
int vis[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	bool zero=true;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> a[i]>> b[i]>> c[i];
			if (b[i]!=0||c[i]1!=0) zero=false;
		}
		if (zero){
			sort (a+1,a+1+n);
			for (int i=n;i>n/2;i--) ans+=a[i];
			cout << ans<< endl;
			continue;4
		}
		else {
			ans=0;
			for(int i=1;i<=n;i++) ans+=max(max(a[i],b[i]),c[i]);
			cout << ans<< endl;
			
	}
	return 0;
}
