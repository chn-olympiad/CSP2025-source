#include <bits/stdc++.h>
//#define int long long
#define debug(x) cout<<#x<<" = "<<x<<' '
#define N 510
#define Mod 998244353
using namespace std;

int n,m,Mn=1,ans,tot;
int a[N],b[N],arr[N];
bool vis[N];

void init(){
	cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++) b[i]=(s[i-1] == '1'),Mn*=b[i];
	
	for(int i=1;i<=n;i++) cin>>a[i];
}

void dfs(int id){
	if(id == n+1){
		int cnt=0,lse=0;
		for(int i=1;i<=n;i++){
			int pos=arr[i];
			if(lse >= a[pos]){lse++;continue;}
			else{
				if(b[i] == 1) cnt++;
				else lse++;
			}
		}
		
		if(cnt >= m) ans=(ans+1)%Mod;
	}
	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			arr[++tot]=i;
			dfs(id+1);
			tot--;
			vis[i]=0;
		}
	}
}

int solve(){
	if(Mn == 1){
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%Mod;
		return ans;
	}else if(n <= 10){
		dfs(1);
		return ans;
	}else return 0;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int T=1;
	while(T--){
		init();
		cout<<solve()<<endl;
	}
	return 0;
}

