#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
string s;
long long n,m,a[10001],c[10001],sum=0,v[10001],jl[10001],cnt=0;
void dfs(int sl,int ts,int Giveup){
	if(sl>n)return;
	if(sl>=m){
		++sum;
		sum%=mod;
		for(int i=1;i<=cnt;i++)cout<<jl[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			jl[++cnt]=i;
			if(a[ts]==0||Giveup>=c[i])dfs(sl,ts+1,Giveup+1);else
			if(a[ts]==1&&Giveup<c[i])dfs(sl+1,ts+1,Giveup);
			jl[cnt--]=0;
			v[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>s;
for(int i=0;i<=s.size()-1;i++)a[i+1]=s[i]-'0';
for(int i=1;i<=n;i++)cin>>c[i];
dfs(0,1,0);
cout<<sum;
	return 0;
}/*
4 2
1010
1 1 2 0

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/