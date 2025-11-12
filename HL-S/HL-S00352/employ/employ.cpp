#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=998244353;
int n,m,p[N],num[N],ans;
bool vis[N];
string s;
void dfs(int x){
	if(x>n){
		int left=0;
		for(int i=1;i<=n;i++){
			if(left>=num[i]||s[i-1]=='0'){
				left++;
			}
		}
		if((n-left)>=m) (ans++)%M;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			num[x]=p[i];
			vis[i]=true;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++) cin>>p[i];
	dfs(1);
	cout<<(ans%M);
	return 0;
}