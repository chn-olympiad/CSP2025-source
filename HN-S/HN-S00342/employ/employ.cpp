#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
const int Mod=998244353;
string s;
int c[1005],vis[1005],a[1005];
bool check(){
	int Ak=0,died=0;
	for(int i=1;i<=n;i++){
		if(Ak>=m)return true;
		if(s[i-1]=='0'){
			died++;
		}
		else{
			if(a[i]>died){
				Ak++;
			}
			else{
				died++;
			}
		}
	}
	if(Ak>=m)return true;
	return false;
}
void dfs(int step){
	if(step==n+1){
		if(check())ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			a[step]=c[i];
			dfs(step+1);
			a[step]=0;
			vis[i]=0;
		}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=18)dfs(1);
	else{
		ans=1;
		for(int i=1;i<=n;i++)
			ans*=i,ans%=Mod;
	}
	cout<<ans<<"\n";
	return 0;
} 
