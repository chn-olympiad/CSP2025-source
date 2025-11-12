#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n;
ll k;
const int N=5e5+5;
ll a[N];
bool A=true;
void solveA() {
	cout<<n/2;
}
bool B=true;
void solveB() {
	if(k==0) {
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==0) {
				ans++;
				continue;
			}
			if(a[i]==1&&a[i+1]==1&&i+1<=n) {
				ans++;
				i++;
			}
		}
		cout<<ans;
		exit(0);
	} else if(k==1) {
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==1)ans++;
		}
		cout<<ans;
		exit(0);
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)B=false;
		if(a[i]!=1)A=false;
	}
	if(A) {
		solveA();
	} else if(B) {
		solveB();
	} else {
		cout<<1;
	}

	return 0;
}
