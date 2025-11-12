#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=500;
int s[maxn+5];
int c[maxn+5];
int p[maxn+5];
bool vis[maxn+5];
int n,m;
const int MOD=998244353;

int ans=0;
void dfs(int k){
	if(k==n+1){
		int out=0;
		for(int i=1; i<=n; i++){
//			cout<<p[i]<<" "<<c[p[i]]<<" "<<s[i]<<" ";
			if(out>=c[p[i]]) out++;
			else if(s[i]==0) out++;
		}
//		cout<<out<<" "<<"\n";
		if(n-out>=m) ans=(ans+1)%MOD;
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			p[k]=i;
			vis[i]=true;
			dfs(k+1);
			vis[i]=false;
		}
	}
}

void special_solve(){
	long long res=1;
	for(int i=2; i<=n; i++){
		res=res*i%MOD;
	}
	ans=res;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int is_special=1;
	string str;
	cin>>str;
	for(int i=1; i<=n; i++){
		s[i]=str[i-1]-'0';
		if(is_special) is_special=min(is_special,(int)s[i]);
	}
	
	for(int i=1; i<=n; i++){
		scanf("%d",&c[i]);
		if(is_special) is_special=min(is_special,c[i]);
	}
	if(is_special) special_solve();
	else dfs(1);
	cout<<ans;
	return 0; //expect: 8+(0~20) pts
}
