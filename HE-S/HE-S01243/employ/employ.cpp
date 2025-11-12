#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
string s;
int n,m,a[N],p[N],ans;
bool vis[N];
bool check(){
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
		if(s[i]=='0'||cnt2>=a[p[i]])
			cnt2++;
		else
			cnt1++;
	return cnt1>=m;
}
void dfs(int x){
	if(x>=n)ans+=check();
	for(int i=0;i<n;i++)
		if(!vis[i])
			vis[i]=1,p[x]=i,dfs(x+1),vis[i]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==m)return cout<<check(),0;
	int cnt1=0;
	for(int i=0;i<n;i++)
		cnt1+=s[i]=='1';
	if(cnt1==n){
		ans=1;
		for(int i=2;i<=n;i++)
			(ans*=i)%=mod;
		return cout<<ans,0;
	}
	if(cnt1<m)
		return cout<<0,0;
	dfs(0);
	cout<<ans;
	return 0;
}
