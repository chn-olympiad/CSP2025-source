#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[1100000];
set<string>ss;
void dfs(long long i,long long val,long long maxx,long long m,string s){
	if(val>maxx*2&&m>=3){
		ss.insert(s);
	}
	if(i>n){
		return;
	}
	dfs(i+1,val+a[i],max(maxx,a[i]),m+1,s+to_string(i)+" ");
	dfs(i+1,val,maxx,m,s);
}
long long _mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long maxx=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		cout<<"0";
		return 0;
	}
	dfs(1,0,0,0,"");
	cout<<ss.size()%_mod;
	return 0;
}
