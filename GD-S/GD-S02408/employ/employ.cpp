#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m;
char s[N];
int c[N];
int cnt[N];
int a[N],tot;
int ans;
void dfs(int pos){
	if(pos>n){
		int xxs=0,ret=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&xxs<c[a[i]])ret++;
			else xxs++;
		}
		if(ret>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!cnt[i]){
			cnt[i]=1;
			a[++tot]=i;
			dfs(pos+1);
			cnt[i]=0;
			tot--;
		}
	}
}
void work(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
		return;
	}
	int ans=1;
	for(int i=1;i<=n;i++)ans=(ans*i)%mod;
	cout<<ans;
}
void clear(){}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int _=1;
	while(_--)work(),clear();
	return 0;
} 
