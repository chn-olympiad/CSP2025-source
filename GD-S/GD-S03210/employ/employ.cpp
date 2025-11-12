#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],ans;
char s[505];
bool f[505];
void dfs(int t,int cnt,int l){
	if(t>n){
		if(cnt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			b[t]=i;
			f[i]=1;
			if(s[i]=='0'||a[i]<=l){
				dfs(t+1,cnt,l+1); 
			}else{
				dfs(t+1,cnt+1,l);
			}
			f[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	s[1]=s[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans-1;
	return 0;
}
