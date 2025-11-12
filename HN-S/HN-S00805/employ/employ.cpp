#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1e6+5,mod=998244353;
int n,m,c[maxn],len,sum,vis[maxn];
int pos[maxn];
string s;
void dfs(int x){
	if(x>n){
		int weiluyong=0,ans=0;
		for(int i=1;i<=n;i++){
			if(weiluyong>=c[pos[i]]){
				weiluyong++;
				continue;
			}
			if(s[i]=='1'){
				ans++;
			}
			else{
				weiluyong++;
			}
		}
		if(ans>=m){
			sum++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			pos[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s; 
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<sum%mod<<endl;
	return 0;
}
/*
20pts
©³©©©©©©©©©©©©©©©· ©³©©©©©©©©©©©©©©©·          ©³©©©©©·                  ©³©©©©©·  
©«   ©³©©©©©·   ©« ©«   ©³©©©©©·   ©«          ©«    ©«                  ©«    ©«
©«   ©«    ©«   ©« ©«   ©«    ©«   ©«          ©«    ©«                  ©«    ©«
©«   ©»©©©©©¿   ©« ©«   ©»©©©©©¿   ©«  ©³©©©©©©©¿    ©»©©©©©©©·  ©³©©©©©©©¿    ©»©©©©©©©·
©«    ©²\    \©©©¿ ©«    ©²©©©©©©©©©¿  ©«                    ©«  ©«                    ©«
©«    ©« \    \    ©«    ©«            ©»©©©©©©©·    ©³©©©©©©©¿  ©»©©©©©©©·    ©³©©©©©©©¿
©«    ©«  \    \   ©«    ©«                    ©«    ©«                  ©«    ©«
©«    ©«   \    \  ©«    ©«                    ©«    ©«                  ©«    ©« 
©»©©©©©¿   ©»©©©©©¿©»©©©©©¿                    ©»©©©©©¿                  ©»©©©©©¿
*/ 
