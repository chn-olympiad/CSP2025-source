# include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
int c[19];
bool vis[19];
int ans;
long long sum;
string s;
int nt(string x){
	for(int i=0;i<x.length();i++){
		if(x[i]=='1'){
			return i;
		}
	}
	return -1;
}
void dfs(int now,int back){
	if(now==n+1){
		if(n-back>=m){
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(back>=c[i]||s[now-1]=='0'){
				vis[i]=true;
//				cout<<"a:"<<now<<" "<<i<<" "<<back<<'\n';
				dfs(now+1,back+1);
				vis[i]=false;
			}else{
				vis[i]=true;
//				cout<<"b:"<<now<<" "<<i<<" "<<back<<'\n';
				dfs(now+1,back);
				vis[i]=false;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n<=12){
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		dfs(1,0);
		cout<<ans;
	}else{
		if(m==1){
			ans=nt(s);
			if(ans==-1){
				cout<<0;
			}else{
				sum=1;
				for(int i=2;i<n;i++){
					sum=(sum*i)%mod;
				}
				long long cnt=0;
				for(int i=1;i<=n;i++){
					cin>>c[1];
					if(c[1]>ans){
						cnt=(cnt+sum)%mod;
					}
				}
				cout<<cnt;
			}
		}else if(m==n){
			cout<<0;
		}else{
			if(nt(s)==-1){
				cout<<0;
			}else{
				sum=1;
				for(int i=2;i<=n;i++){
					sum=(sum*i)%mod;
				}
				cout<<sum;
			}
		}
	}
	return 0;
}