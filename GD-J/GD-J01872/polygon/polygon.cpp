#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long n,a[maxn],mod=998244353,ans,cnt=1;
string s[maxn];
bool vis[maxn],m[maxn];
set<int> v;
bool p1(string s3){
	if(s3.size()<3) return false;
	int x=0,y=0;
	for(int i=0;i<s3.size();i++){
		if(s3[i]>='0'&&s3[i]<='9'){
			x+=(s3[i]-'0');
			y=max(y,(s3[i]-'0'));
		}
	}
	if(x>y*2) return true;
	return false;
}
bool p2(string s1,string s2){
	return s1==s2?false:true;
}
void dfs(int dep){
	if(dep==n+1){
		for(int u:v) s[cnt]+=(u+'0');
		cnt++;
		v.clear();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		v.insert(a[i]);
		vis[i]=true;
		dfs(dep+1);
		vis[i]=false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1);
	for(int i=2;i<=cnt;i++){
		for(int j=i-1;j>=1;j--){
			if(!p2(s[i],s[j])){
				m[i]=true;
				break;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(!m[i]){
			if(p1(s[i])){
				ans++;
				ans%=mod;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
