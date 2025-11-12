#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
string s;
bool vis[505];
int a[505];
vector<int> v;
long long ans;
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=0;i<n;i++){
			int b=0;
			if(s[i]=='0' || b>=a[v[i]]){
				b++;
				continue;
			}else cnt++;
		}if(cnt>=m) ans++;
		return;
	}for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			v.push_back(i);
			dfs(x+1);
			v.pop_back();
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans%N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
