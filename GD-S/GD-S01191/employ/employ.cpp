#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],p[N];
string s;
int dfs(int dep,int ans){
	if(ans>m)return 0;
	if(dep>n)return 1;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i])continue;
		p[i]=1;
		if(s[dep]=='0'||ans>=a[i]){
			cnt+=dfs(dep+1,ans+1);
		}else{
			cnt+=dfs(dep+1,ans);
		}
		p[i]=0;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	m=n-m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	cout<<dfs(1,0);
	return 0;
} 
