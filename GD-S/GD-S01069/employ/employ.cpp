#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
string s;
int c[510],a[510];
bool b[510];
void dfs(int x,int t,int sum){
	if(x>=m&&x+t==n){
		ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			if(s[x+t]=='1'){
				if(t<c[i]){
					b[i]=1;
					a[sum]=i;
					dfs(x+1,t,sum+1);
					b[i]=0;
				}else{
					b[i]=1;
					dfs(x,t+1,sum+1);
					b[i]=0;
				}
			}else{
				b[i]=1;
				dfs(x,t+1,sum+1);
				b[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0,0,1);
	cout<<ans;
}

