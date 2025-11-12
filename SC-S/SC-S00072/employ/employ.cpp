#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int mod=998244353;
long long n,m,a[50005],pd1,pd2,ans,fac[50005],sum[50005];
bool vis[50005];
map<pair<int,int>,bool>mp;
string s;
void dfs(int now,int us,int no){
	if(us==m and now<=n and !mp[make_pair(us,no)]){
		mp[make_pair(us,no)]=true,++ans;
		return;
	}
	for(int day=now+1;day<=n;day++){
		if(s[day]=='0'){
			for(int i=1;i<=n;i++){
				if(no>=a[i] or vis[i]) continue;
				else{
					++no,vis[i]=true;
					dfs(day,us,no);
					--no,vis[i]=false;	
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(no>=a[i] or vis[i]) continue;
				else{
					++us,vis[i]=true;
					dfs(day,us,no);
					--us,vis[i]=false;
				}
			}	
		}	
	}
	return;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s='#'+s;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='0');
	init();
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='1') ++pd1;
		else ++pd2;
	}
	if(pd2==n or (pd1<n and a[1]==0 and m==n)){
		cout<<"0";
		return 0;
	}
	if(m==1){
		int meno=1;
		for(int i=1;i<=n;i++){
			if(s[i]!='0'){
				meno=i;
				break;
			}
		}
		int x=lower_bound(a+1,a+n+1,meno)-a;
		cout<<(fac[x]+fac[min(n-x,a[n]-sum[n])])%mod;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
