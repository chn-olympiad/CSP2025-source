#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
const long long MAXN=998244353;
string s;
int c[505];
void dfs(int i,set<int>st,int num,int fail){
	if(c[i]<=fail){
		return ;
	}
	if(s[n-st.size()]=='1'){
		num++;
	}else{
		fail++;
	}
	st.erase(i);
	if(st.size()==0){
		if(num>=m){
			ans++;
			if(ans==MAXN)ans=0;
		}
		return ;
	}
	for(auto j:st){
		dfs(j,st,num,fail);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	set<int>st;
	for(int i=1;i<=n;i++)st.insert(i);
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		dfs(i,st,0,0);
	}
	cout<<ans;
}
/*
CSP-S T4 Employ
*/
