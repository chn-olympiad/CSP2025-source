#include<bits/stdc++.h>
using namespace std;
const long long int mod=998244353;
int n,m;
int a[20],c[502];
int vis[20];
long long ans=0;
string s;

bool check(){
	int cnt=0;
	int failed=0;
	for(int i=1;i<=n;i++){
		if((s[i-1]=='1')&&failed<c[a[i]]){
			cnt++;
		}else{
			failed++;
		}
	}
	return cnt>=m;
}

void solve(int x){
	if(x==n+1){
		if(check()){
			ans++;
		}
		if(ans>mod){
			ans-=mod;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				a[x]=i;
				vis[i]=true;
				solve(x+1);
				vis[i]=false;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	solve(1);
	cout<<ans;
	return 0;
}
