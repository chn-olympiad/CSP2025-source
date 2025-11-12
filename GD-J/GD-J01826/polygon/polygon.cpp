#include<bits/stdc++.h>
using namespace std;
bool st[5010];
int a,s[5010],ans;
map<string,int>mp;
void dfs(int goal,int step,int sum,int mx) {
	if(step>goal) {
		if(sum>mx*2) {
			string c="";
			for(int i=1; i<=a; i++) {
				if(st[i])c+=i+'0';
			}
			if(mp[c]!=1) {
				ans++;
				mp[c]=1;
			}
		}
		return;
	}
	for(int i=step; i<=a; i++) {
		if(!st[i]) {
			st[i]=1;
			dfs(goal,step+1,sum+s[i],max(mx,s[i]));
			st[i]=0;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1; i<=a; i++) {
		cin>>s[i];
	}
	sort(s+1,s+a+1);
	for(int i=3; i<=a; i++) {
		for(int j=1; j<=a; j++) {
			st[j]=0;
		}
		for(auto i:mp) {
			i.second=-1;
		}
		dfs(i,1,0,-1);
	}
	cout<<ans<<endl;
	return 0;
}
