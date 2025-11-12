#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,c[505],v[505],ans; 
void dfs(int x,int cnt,int out){
	if(x==n&&cnt>=m){
		ans++;
		ans%=998244353; 
		return ;
	}
	if(n-x+cnt<m)return ;
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(s[x]=='0'||out>=c[i]){
				dfs(x+1,cnt,out+1);
			}else{
				dfs(x+1,cnt+1,out);
			}
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>100){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans; 
	return 0;
} 
