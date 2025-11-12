#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1010],use[1010],num[1010],ans=0;
char s[1010];
void pd(){
	int k=0,w=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')
			k++;
		else if(num[i]>k)
			w++;
	}
	if(w>=m){
		ans++;
		ans=ans%998244353;
	}
}
void dfs(int k){
	if(k>n){
		pd();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(use[i]==0){
			num[k]=c[i];
			use[i]=1;
			dfs(k+1);
			use[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
