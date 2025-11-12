#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
int c[505],a[505];
string s;
int cnt[505];
vector<int>e;
void dfs(int p,int ct){
	if(p==n+1){
		ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!cnt[i]){
			if(a[p]==0||ct>=c[i]){
				ct++;
				if(n-ct<m){
					ct--;
					continue;
				}
				else{
					cnt[i]=1;
					e.push_back(i);
					dfs(p+1,ct);
					e.pop_back();
					cnt[i]=0;
					ct--;
				}
			}
			else{
				cnt[i]=1;
				e.push_back(i);
				dfs(p+1,ct);
				e.pop_back();
				cnt[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char cc;
		cin>>cc;
		a[i]=(int)(cc-'0');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
