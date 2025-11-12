#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,s1,a[555],v[555];
char s[555];
int dfs(int x,int c,int t){
	if(x>n){
		if(t>=m) return 1;
		return 0;
	}
	int res=0;
	if(c>=a[x]||s[x]==1) c++;
	else t++;
	for(int i=1;i<=n;i++) if(!v[i]) v[i]=1,(res+=dfs(x+1,c,t))%=mod,v[i]=0;
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++) s1+=(s[i]=='1'),cin>>a[i];
	if(s1==n) return cout<<(m==0?1:0),0;
	if(m==n&&s1>0) return cout<<0,0;
	return cout<<dfs(1,0,0),0;
}
