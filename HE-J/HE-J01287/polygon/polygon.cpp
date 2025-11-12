#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,sum,ans;
int a[5005];
vector<int>v;
void dfs(int x) {
	ans%=Mod;
	int maxx=0;
	for(int i=1; i<v.size(); i++) {
		maxx=max(maxx,v[i]);
	}
	if(sum>(maxx*2)) ans++;
	if(x==n+1) {
		return;
	}
	for(int i=x; i<=n; i++) {
		v.push_back(a[i]);
		sum+=a[i];
		dfs(i+1);
		sum-=a[i];
		v.pop_back();
	}
}
int main() {
//	freopen("polygon.in","r", stdin);
//	freopen("polygon.ans","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];
	}
	v.push_back(0);
	dfs(1);
	cout <<ans%Mod<<endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

