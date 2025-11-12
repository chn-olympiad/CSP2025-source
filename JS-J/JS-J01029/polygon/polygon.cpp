#include<bits/stdc++.h>
using namespace std;
long long cnt,n;
bool vis[5005];
long long a[5005];
void DFS(long long ans,long long mx,long long i,long long g) {
	long long l=mx+mx;
	if(ans>l&&g>=3) {
		cnt++;
	}
	if(i==n) return;
	for(int j=i+1;j<n;j++) {
		if(vis[j]==true) continue;
		else {
			vis[j]=true;
			DFS(ans+a[j],mx=max(mx,a[j]),j,g+1);
			vis[j]=false;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	DFS(0,0,-1,0);
	cout<<cnt%998244353;
	return 0;
}
