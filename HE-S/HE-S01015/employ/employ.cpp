#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
int s[505];
long long ans=1;
bool f1() {
	for(int i=1;i<=m;i++) {
		if(s[i]==0) {
			return false;
		}
	}
	return true;
}
bool f2() {
	for(int i=1;i<=m;i++) {
		if(s[i]==1) {
			return false;
		}
	}
	return true;
}
int f3() {
	int cnt=0;
	for(int i=1;i<=m;i++) {
		if(s[i]==0) {
			cnt++;
		}
	}
	return cnt;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		char a;
		cin >> a;
		s[i]=a-'0';
	}
	int mn=550;
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
		mn=min(mn,c[i]);
	}
	if(f1()) {
		for(int i=1;i<=m;i++) {
			ans*=i; 
		}
		cout << ans%998244353;
		return 0;
	}
	if(f2()) {
		cout << 0;
		return 0;
	} 
	if(f3()<mn) {
		int sum=0;
		for(int i=1;i<m;i++) {
			sum+=i; 
		}
		cout << sum%998244353;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
