#include<bits/stdc++.h>
using namespace std;

int n,maxn,sum,ans,a[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxn = max(maxn,a[i]);
		sum += a[i];
	}
	if(n==3){
		if(sum > 2*maxn) cout << 1;
		else cout << 0;
		return 0;
	}
	if(n==4){
		if(sum > 2*maxn) ans++;
		if(a[1]+a[2]+a[3] > 2*max(a[1],max(a[2],a[3]))) ans++;
		if(a[1]+a[2]+a[4] > 2*max(a[1],max(a[2],a[4]))) ans++;
		if(a[4]+a[2]+a[3] > 2*max(a[4],max(a[2],a[3]))) ans++;
		cout << ans;
		return 0;
	}
	if(n==5){
		if(sum > 2*maxn) ans++;
		if(a[1]+a[2]+a[3] > 2*max(a[1],max(a[2],a[3]))) ans++;
		if(a[1]+a[2]+a[4] > 2*max(a[1],max(a[2],a[4]))) ans++;
		if(a[4]+a[2]+a[3] > 2*max(a[4],max(a[2],a[3]))) ans++;
		if(a[1]+a[2]+a[5] > 2*max(a[1],max(a[2],a[5]))) ans++;
		if(a[4]+a[2]+a[3] > 2*max(a[4],max(a[2],a[3]))) ans++;
		if(a[5]+a[2]+a[3] > 2*max(a[5],max(a[2],a[3]))) ans++;
		if(a[4]+a[5]+a[3] > 2*max(a[4],max(a[5],a[3]))) ans++;
		if(a[4]+a[2]+a[3]+a[1] > 2*max(a[1],max(a[4],max(a[2],a[3])))) ans++;
		if(a[4]+a[2]+a[3]+a[5] > 2*max(a[5],max(a[4],max(a[2],a[3])))) ans++;
		if(a[4]+a[1]+a[3]+a[5] > 2*max(a[5],max(a[4],max(a[1],a[3])))) ans++;
		if(a[4]+a[2]+a[1]+a[5] > 2*max(a[5],max(a[4],max(a[2],a[1])))) ans++;
		if(a[1]+a[2]+a[3]+a[5] > 2*max(a[5],max(a[1],max(a[2],a[3])))) ans++;
		cout << ans ;
		return 0;
	}
	cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
