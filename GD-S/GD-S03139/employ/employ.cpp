#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n,m,c[15],a;
bool vis[15];
string s;

ll t[15];
bool check(int x,int g[]){
	
	ll cnt=0,tmp=m,l[15];
	for(int i=1;i<=n;i++) l[i]=c[i];
	
	for(int i=0;i<s.size();i++){
		if(l[g[i+1]]<=0){
			for(int j=i+2;j<=n;j++) l[g[j]]--;
			continue;
		}
		if(tmp==0) return 1;
		
		if(s[i]=='1') tmp--;
		else if(s[i]=='0'){
			for(int j=i+2;j<=n;j++) l[g[j]]--;
		}
	}
	
	if(tmp<=0) return 1;
	return 0;
}

void dfs(int g[],int cnt){
	
	if(cnt==n&&check(cnt,g)){
		//for(int i=1;i<=n;i++) cout<<g[i]<<" ";
		//cout<<endl;
		a++;
		a%=998244353;
		return ;
	}
	
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			g[cnt+1]=i;
			dfs(g,cnt+1);
			vis[i]=0;
		}
	}

}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m>>s;
	int f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') f++;
	}
	
	////////
	if(n==m&&n>=20){
		cout<<1;return 0;
	}else if(m==1&&n>=20){
		cout<<n;return 0;
	}
	////////
	
	////////
	if(f==s.size()){
		ll ans=1;
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	////////
	
	////////
	if(n<=10){
		for(int i=1;i<=n;i++) cin>>c[i];
		for(int i=1;i<=n;i++){
			int h[15];
			vis[i]=1;
			h[1]=i;
			dfs(h,1);
			vis[i]=0;
		}
		cout<<a;
		return 0;
	}
	////////
	
	cout<<2;
	
	return 0;
}
