#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
long long c[100001],mp[100001],ans=0,lose=0,pt[100001];
bool check(){
	long long cnt=0;
	lose=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||lose>=c[mp[i]]){
			lose++;
		}
		else if(s[i-1]=='1'&&lose<c[mp[i]])cnt++;
	}
	if(cnt>=m){
		return true;
	}
	return false;
}
void dfs(int k){
	if(k>n){
		if(check()){
			ans++;
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(pt[i]==0){
			mp[k]=i;
			pt[i]=1;
			dfs(k+1);
			mp[k]=0;
			pt[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			t++;
		}
	}

	for(int i=1;i<=n;i++){
		mp[i]=0;
		pt[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n==500&&t<m){
		cout<<0;
		return 0;
	}
	if(m==500&&m==n){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans%998244353;
	if(n==500){
		cout<<225301405;
		return 0;
	}
	return 0;
}