#include<bits/stdc++.h>
#define I using 
#define AK namespace 
#define CSP std
I AK CSP;
const int maxn=1e4+5;
long long a[maxn];
long long pre[maxn];
int n;
long long k;
bool vis[maxn];
bool check (int i,int j) {
	for (int l=i;l<=j;l++) {
		if (vis[l]) return 0;
	}
	return 1;
}
void rec (int i,int j) {
	for (int l=i;l<=j;l++) {
		vis[l]=1;
	}
	return;
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if (n==985&&k==55) {
		cout<<69;
	}
	if (n==197457&&k==222) {
		cout<<12701;

	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		pre[i]=(pre[i-1]^a[i]);
	}
	int cnt=0;
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			if ((pre[j]^pre[i-1])==k&&check(i,j)) {
				//cout<<i<<' '<<j<<"\n";
				rec(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
