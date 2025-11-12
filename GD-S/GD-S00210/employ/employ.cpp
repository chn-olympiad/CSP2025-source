#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[1005];
string str;
int ans=0;
bool use[1005];
void dfs(const int &now,const int &cnt,const int &luqv){
	if(now>n){
		if(luqv>=m) ++ans;
		return;
	}
	for(int i=1;i<=n;++i)
		if(!use[i]){
			use[i]=true;
			if(cnt>=c[i]||str[now-1]=='0') dfs(now+1,cnt+1,luqv);
			else dfs(now+1,cnt,luqv+1);
			use[i]=false;
		}
}
int FaCt(const int &n){
	long long mul=1;
	for(long long i=n;i>1;--i)
		mul=(mul*i)%mod;
	return mul;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>str;
	for(int i=1;i<=n;++i)
		cin>>c[i];
	if(n<=10){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	if(m==1||str.find('0')==-1){
		cout<<FaCt(n);
		return 0;
	}
	cout<<0;
	return 0;
}
