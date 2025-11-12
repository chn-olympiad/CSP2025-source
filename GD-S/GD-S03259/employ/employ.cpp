#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
using namespace std;
using ll=long long;
const int p=998244353;
int n,m,c[505],A[505],ans;
bool vis[505];
string s;
void dfs(int l){
	if(l==n+1){
		int out=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(out>=c[A[i]]||s[i]=='0') out++;
			else cnt++;
		}
		ans+=(cnt>=m),ans%=p;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		A[l]=i,vis[i]=true;
		dfs(l+1);
		vis[i]=false;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
} 
