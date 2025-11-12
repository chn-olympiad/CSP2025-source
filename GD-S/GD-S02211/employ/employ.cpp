#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=505;
const long long mod=998244353;
int n,m,c[maxn];
bool vis[maxn];
string s;
long long ans;
void dfs(int x,int p){
	//为第x天选人 此前有x个人参与面试 通过p个人 
	if(x==n){
		if(p>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(s[x]=='0'||x-p>=c[i]){
				dfs(x+1,p);
			}else{
				dfs(x+1,p+1);
			}
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0);
	cout<<ans;
} 
//20pts
