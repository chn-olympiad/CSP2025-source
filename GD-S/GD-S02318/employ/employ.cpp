#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,m,c[505];
char s[505];
long long ans;
bool f[505];

void dfs(int k,int t){
	if(k>n&&t>=m){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		if(s[k]=='1'&&c[i]>k-1-t){
			f[i]=1;
			dfs(k+1,t+1);
			f[i]=0;
		}else{
			f[i]=1;
			dfs(k+1,t);
			f[i]=0;
		}
	}
	
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	
	dfs(1,0);
	cout<<ans;
} 
