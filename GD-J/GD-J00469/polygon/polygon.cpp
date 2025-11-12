#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;

void dfs(vector<int>& s,int depth,int start,int value) {
	if(depth>n) return;
	else {
		for(int i=start;i<n;i++) {
			if(depth>=3) ans+=(value>s[start-1]*2?1:0);
			dfs(s,depth+1,i+1,value+s[i]);
			ans%=998244353;
		}
	}
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	cin>>n;
	vector<int> s(n);
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s.begin(),s.end());
//	dfs(s,0,0,0);
	for(int i=0;i<n;i++) {
		for(int j=i+2;j<n;j++) {
			int value=(j==i+2?s[i]+s[i+1]+s[i+2]:value+s[j]);
			if(value>s[j]*2) ans++;
			ans=ans%998244353;
		}
	}
	cout<<ans;
	
}
