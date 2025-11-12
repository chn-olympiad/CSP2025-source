#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
const int mod=998244353;
string s;
int n,m;
int c[N];
int b[N];
bool vis[N];
int ans=0;
void dfs(int sum,int num,int ou){
	if(num==n+1){
		if(sum>=m) ans=(ans+1)%mod;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(s[num]=='0'||ou>=c[i]){
				vis[i]=1;
				dfs(sum,num+1,ou+1);
			}
			else if(s[num]=='1'&&ou<c[i]){
				vis[i]=1;
				dfs(sum+1,num+1,ou);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s='#'+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1];
		if(s[i]=='0') b[i]++;
	}
	dfs(0,1,0);
	cout<<ans<<"\n";
	return 0;
}

