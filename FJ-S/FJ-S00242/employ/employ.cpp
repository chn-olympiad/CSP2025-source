#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[505],a[15],ans;
string s;
bool pd[15];
void dfs(int now){
	if(now>n){
		int cnt=0,res=0;
		for(int i = 1;i<=n;i++){
			if(s[i-1]=='0') cnt++;
			else if(cnt<c[a[i]]) res++;
			else cnt++; 
		}
		ans+=res>=m;
		return;
	} 
	for(int i = 1;i<=n;i++){
		if(!pd[i]){
			pd[i]=1;
			a[now]=i;
			dfs(now+1);
			pd[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i = 1;i<=n;i++) cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else{
		ans=1;
		for(int i = 1;i<=n;i++)
			(ans*=i)%=mod;
		cout<<ans;
	}
	return 0;
}
