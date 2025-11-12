#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
long long a[5010];
map<string,int> mp;
void dfs(long long x,long long he,long long maxn,long long gs,string s){
	if(he>maxn*2&&gs>=3&&mp[s]==0){
		cnt++;
		cnt%=998244353;
		mp[s]++;
	}
	if(x==n+1){
		return;
	}
	dfs(x+1,he,maxn,gs,s);
	char c=x+'0';
	dfs(x+1,he+a[x],max(maxn,a[x]),gs+1,s+' '+c);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0,"");
	cout<<cnt;
	return 0;
}
