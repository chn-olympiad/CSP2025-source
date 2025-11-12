#include<bits/stdc++.h>

using namespace std;

int n,a[6000];
bool flag[6000];

int dfs(int k, int x, int c) {
	if(k>n && c!=0) {
		return 0;
	}
	if(c==0) {
		int longest = 0, tt = 0;
		for(int i=1;i<=n;i++) {
			if(flag[i]==true) {
				longest = max(a[i], longest);
				tt+=a[i];
			}
		}
		if(longest*2<tt) return 1;
		return 0;
	}
	int ans = 0;
	flag[k] = true;
	ans += dfs(k+1,x,c-1);
	flag[k] = false;
	ans += dfs(k+1,x,c);
	return ans;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	
	int ans = 0;
	
	for(int i=3;i<=n;i++) {
		for(int i=1;i<=n;i++) {
			flag[i] = false;
		}
		ans += dfs(1,i,i);
	}
	
	cout<<ans;
	
	return 0;
}
