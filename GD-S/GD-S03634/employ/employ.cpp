#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=504;
const int MOD=998244353;
ll n,m,ans,c[N],p[N],d[N];
string s;
bool flag,vis[N];
void dfs(ll cur,ll cnt){
	if(cur>n){
		if(cnt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(s[cur-1]=='0'||cur-cnt>c[i]){
				dfs(cur+1,cnt);
			}else{
				dfs(cur+1,cnt+1);
			}
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(s[i-1]=='0'){
			flag=true;
		}
	}
	if(n<=10){
		dfs(1,0);
	}else if(!flag){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%MOD;
		}
	}else if(m==n){
		for(int i=1;i<=n;i++){
			if(!c[i]){
				flag=true;
			}
		}
		if(!flag){
			ans=1;
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'){
				for(int j=1;j<=n;j++){
					if(c[j]>=i){
						d[i]++;
						ll now=1;
						for(int k=1;k<i;k++){
							now=(now*(n-d[k]-k+1))%MOD;
						}
						for(int k=i+1;k<=n;k++){
							now=(now*(n-k+1))%MOD;
						}
						ans=(ans+now)%MOD;
					}
				}
				if(d[i]==n){
					break;
				}
			}else{
				d[i]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
