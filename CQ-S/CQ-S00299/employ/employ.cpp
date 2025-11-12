#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m;
int a[N];
int c[N];
string s;
bitset<N>vis;
int ans=0;
void dfs(int k){
	if(k==n+1){
		int die=0,re=0;
		for(int i=1;i<=n;i++){
			if(die>=c[a[i]]||s[i]=='0')die++;
			else{
				re++;
			}
		}
		if(re>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
bool _A=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s='$'+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
