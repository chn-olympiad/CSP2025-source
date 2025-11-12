#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[510],b[510];
char s[510];
bool v[510],f=1;
ll ans;
inline void dfs(int k){
	if(k>n){
		int c=0;
		for(int i=0,j=1;j<=n;i++,j++){
			while(j-c>a[b[j]]&&j<=n) j++;
			if(j>n) break;
			if(s[i]=='1') c++;
		}
		if(c>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			b[k]=i;
			dfs(k+1);
			b[k]=0;
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s);
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			f=0;
			break;
		}
	}
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	if(f){
		ans=1;
		for(ll i=n;i>=2;i--){
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	else{
		dfs(1);
		cout<<ans%998244353;
	}
}
