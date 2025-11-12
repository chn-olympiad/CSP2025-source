#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],t[N],v[N],ans;
string s;
void dfs(int s1,int cnt){
	if(n-cnt<m)
		return;
	if(s1>n){
		if(n-cnt>=m)
			ans=(ans+1)%mod;	
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			t[s1]=i;
			v[i]=1;
			int cnt1=cnt;
			if(c[i]<=cnt1||s[s1]=='0')
				cnt1++;
			dfs(s1+1,cnt1);
			t[s1]=0;
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
