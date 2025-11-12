#include<bits/stdc++.h>
using namespace std;
const int N=507,MOD=998244353;
int n,m,c[N],st[N];
string s;
long long res,steps[N]={1};
void dfs(int idx,int l,int p){
	if(n-idx<m-l)	return;
	if(l==m){
		res+=steps[n-idx],res%=MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i])	continue;
		st[i]=1;
		if(p>=c[i])	dfs(idx+1,l,p+1);
		else	dfs(idx+1,l+(s[idx]=='1'),p+(s[idx]=='0'));
		st[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	for(int i=1;i<N;i++)	steps[i]=steps[i-1]*i,steps[i]%=MOD; 
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	sort(c+1,c+n+1);
	dfs(0,0,0);
	cout<<res<<endl;
	
	fclose(stdin);
	fclose(stdout);
}/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
