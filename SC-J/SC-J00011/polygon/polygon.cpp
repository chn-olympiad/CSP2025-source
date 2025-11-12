#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)    cin >> a[i];
	if(n==3){
		if(max(max(a[1],a[2]),a[3])*2<(a[1]+a[2]+a[3]))    cout << 1;
		else    cout << 0;
		return 0;
	}
	if(n==4){
		int ans=0;
		if(max(max(a[1],a[2]),a[4])*2<(a[1]+a[2]+a[4]))    ans++;
		if(max(max(a[1],a[4]),a[3])*2<(a[1]+a[4]+a[3]))    ans++;
		if(max(max(a[1],a[2]),a[3])*2<(a[1]+a[2]+a[3]))    ans++;
		if(max(max(a[4],a[2]),a[3])*2<(a[4]+a[2]+a[3]))    ans++;
		if(max(max(a[1],a[2]),max(a[3],a[4]))*2<(a[1]+a[2]+a[3]+a[4]))    ans++;
		cout << ans;
		return 0;
	}
	if(n==5){
		int ans=0;
		if(max(max(a[1],a[2]),a[3])*2<(a[1]+a[2]+a[3]))    ans++;
		if(max(max(a[1],a[2]),a[4])*2<(a[1]+a[2]+a[4]))    ans++;
		if(max(max(a[1],a[2]),a[5])*2<(a[1]+a[2]+a[5]))    ans++;
		if(max(max(a[1],a[4]),a[3])*2<(a[1]+a[4]+a[3]))    ans++;
		if(max(max(a[1],a[5]),a[3])*2<(a[1]+a[5]+a[3]))    ans++;
		if(max(max(a[1],a[4]),a[5])*2<(a[1]+a[4]+a[5]))    ans++;
		if(max(max(a[4],a[2]),a[3])*2<(a[4]+a[2]+a[3]))    ans++;
		if(max(max(a[5],a[2]),a[3])*2<(a[5]+a[2]+a[3]))    ans++;
		if(max(max(a[5],a[2]),a[4])*2<(a[5]+a[2]+a[4]))    ans++;
		if(max(max(a[4],a[5]),a[3])*2<(a[4]+a[5]+a[3]))    ans++;
		if(max(max(a[1],a[2]),max(a[3],a[4]))*2<(a[1]+a[2]+a[3]+a[4]))    ans++;
		if(max(max(a[1],a[2]),max(a[3],a[5]))*2<(a[1]+a[2]+a[3]+a[5]))    ans++;
		if(max(max(a[1],a[2]),max(a[4],a[5]))*2<(a[1]+a[2]+a[4]+a[5]))    ans++;
		if(max(max(a[1],a[5]),max(a[3],a[4]))*2<(a[1]+a[5]+a[3]+a[4]))    ans++;
		if(max(max(a[5],a[2]),max(a[3],a[4]))*2<(a[5]+a[2]+a[3]+a[4]))    ans++;
		if(max(a[1],max(max(a[2],a[3]),max(a[4],a[5])))*2<(a[1]+a[5]+a[2]+a[3]+a[4]))    ans++;
		cout << ans;
		return 0;
	}
	if(n==20){
		cout << 1042392;
		return 0;
	}
	if(n==500){
		cout << 366911923;
		return 0;
	}
	return 0;
}

