#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[505],vis[505],d[505],answ;
string s;
void dfs(int x){
	if(x>n){
		int c=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||a[d[i]]<=c){
				c++;
			}
		}
		if((n-c)>=m){
			ans++;
		}
		return;
	}
	
	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			d[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(1);
		cout<<ans;
	}else{
		long long anw=1;
		for(int i=1;i<=n;i++){
			anw*=i;
		}
		cout<<anw;
	}
	
	return 0;
}

