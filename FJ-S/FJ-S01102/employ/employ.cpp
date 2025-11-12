#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[510],b[510],ans,c[510];
string s;
bool check(){
	int l=0,sum=0;
	for(int i=1;i<=n;i++){
		if(a[c[i]]<=l||s[i-1]=='0'){
			l++;
		}
		else{
			sum++;
		}
	}
	return sum>=m;
}
void dfs(int x){
	if(x>n){
		if(check()){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			c[x]=i;
			dfs(x+1);
			b[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
