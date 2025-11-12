#include <bits/stdc++.h>
using namespace std;
const int N=600;
int n,m,p,len,ans,idx,k[N],c[N],pl[N],vis[N];
string s;
bool cmp (int x,int y) {
	return x<y;
}
void dfs(int d) {
	if (d==n+1) {
		int cnt=0,fai=0;
//		for (int i=1;i<=n;i++) cout <<pl[i] <<" ";
		for (int i=1;i<=n;i++) {
			if (s[i-1]=='0' || c[pl[i]]<=fai) {
				fai++;
		//		cout <<i <<"  ";
			} else {
				cnt++;
			}
		}
		if (cnt>=m) {
			ans++;
			
			
		}
		return;
	}
	for (int i=1;i<=n;i++) {
		if (!vis[i]) {
			vis[i]=1;
			pl[d]=i;
			dfs(d+1);
			vis[i]=0;
		}
	}
	return;
}
int main() {
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n >>m >>s;
	for (int i=1;i<=n;i++) {
		cin >>c[i];
	}
	len=s.size();
	for (int i=0;i<len;i++) {
		if (c[i]=='0') {
			k[++idx]=i;
		}
	}
	p=n-idx-m;
	sort (c+1,c+n+1,cmp);
	dfs (1);
	cout <<ans;
	return 0;
}

