#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c[505],l[505],ans,temp[505],ty=1,has=0;
bool vis[505];
char test[505];
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++) temp[i]=c[i];
	for(int i=1;i<=n;i++){
		if(temp[l[i]]<=0){
			for(int j=1;j<=n;j++) temp[j]--;
			continue;
		}
		if(test[i]=='0'){
			for(int j=1;j<=n;j++) temp[j]--;
			continue;
		}
		else cnt++;
	}
	return (cnt>=m);
}
void dfs(int x){
	if(x>n){
		if(check()){
			ans=((ans%mod)+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			l[x]=i;
			dfs(x+1);
			l[x]=0;
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>test[i];
		if(test[i]!='1') ty=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) has=1;
	}
	if(m==n){
		if(ty==0) cout<<0;
		else{
			if(has==1) cout<<0;
			else{
				ans=1;
				for(int i=1;i<=n;i++){
					ans=(ans%mod)*(i%mod)%mod;
				}
				cout<<ans;
			}
		}
	}
	else{
		dfs(1);
		cout<<ans;	
	}
	return 0;
}

