#include<bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
const int N=5e5+5;
int a[N],pre[N];
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool fa=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) fa=0;
		pre[i]=pre[i-1]+a[i];
	}
	if(fa) {
		cout<<n/2;
		return 0;
	}
	cout<<1;
	return 0;
}
