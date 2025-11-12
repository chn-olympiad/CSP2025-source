#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int a[N],n,k,sum;
string s;
map<int,int> mp;
void dfs(int x,int c){
	if(x>=n){
		if(n-c>=k)sum=(sum+1)%mod;
		return;
	}
	for(int i=0;i<n;i++){
		if(mp[i])continue;
		mp[i]=1;
		int cc=0;
		if(s[x]=='0')cc=1;
		if(c>=a[i])cc=1;
		dfs(x+1,c+cc);
		mp[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		mp[i]=1;
		int c;
		if(s[0]=='0')c=1;
		else c=0;
		dfs(1,c);
		mp[i]=0;
	}
	cout<<sum;
}
