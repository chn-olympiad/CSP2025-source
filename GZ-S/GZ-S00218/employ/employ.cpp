//GZ-S00218 贵阳市白云区华师一学校 李坤元 
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char s[100005];
int c[100005];
bool st[100005];
int k[100005];
int ans=0;
bool flag=false;
void dfs(int p,int sum){
	if(k[p]+sum<m) return;
	if(p==n+1){
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i]) continue;
		st[i]=true;
		if(p-sum-1<c[i]&&s[p]=='1') dfs(p+1,sum+1);
		else dfs(p+1,sum);
		st[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1') flag=true;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=20){
		for(int i=n;i>=1;i--){
			k[i]=k[i+1];
			if(s[i]=='1') k[i]++;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	else{
		cout<<0;
	}
	return 0;
}
