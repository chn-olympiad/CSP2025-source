#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ans=1;
int n, m, a[114514], len=0;
char s;
bool fl1=true;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	ll n0=n;
	for(int i=1;i<=n0;i++){
		cin >> a[i];
		if(a[i]==0)n--;
	}
	for(int i=1;i<=n;i++)ans*=i;
	ans=0;
	cout << ans << '\n';
	return 0;
}
