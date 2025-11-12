#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=510,mod=998244353;
int s[N],c[N];
int f[N],cnt;
bool vis[N];
long long ans=0;
void dfs(int gs){
	if(gs>n){
//		for(int i=1;i<=cnt;i++) cout<<f[i]<<" ";
//		cout<<endl;
		int sum=0;
		for(int i=1;i<=cnt;i++){
			if(sum>=c[f[i]]){
				sum++;//放弃+1
			}
			else{
				if(s[i]==0){//第i天的题的难度 
					sum++;//放弃+1 
				}
			} 
		}
		if(n-sum>=m){
//			for(int i=1;i<=cnt;i++) cout<<f[i]<<" ";
//			cout<<"****************"<<endl;
			ans=(ans%mod+1)%mod;
		} 
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		cnt++;
		f[cnt]=i;
		dfs(gs+1);
		vis[i]=0;
		cnt--; 
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ss;
		cin>>ss;
		s[i]=(ss-'0');
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
		dfs(1);
		cout<<ans<<endl;
	}else{
		unsigned long long xx=1;
		for(int i=1;i<=n;i++) xx=(xx%mod*(1ll*i%mod))%mod;
		cout<<xx%mod<<endl; 
	} 
	
	
	return 0;
}
