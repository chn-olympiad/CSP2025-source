#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,mod=998244353;
ll n,m,t,q[N],ans;
ll c[N];
ll f[(1<<18)+5][20]; 
bool vis[N];
string s;
bool flag=1;
bool check(){
//	for(int i=1;i<=n;i++) printf("%lld ",q[i]);
//	printf("\n");
	int sum=0,t=0;
	for(int i=1;i<=n;i++){
//		cout<<s[i-1]<<" ";
		if(s[i]=='0') sum++;
		else{
			if(c[q[i]]>sum) t++;
			else sum++;
		}
	}
	return t>=m;
} 
void dfs(ll x){
	if(x>n){
		if(check()) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1,q[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]!='1') flag=0;
	}
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	if(n<=10){
		dfs(1);
		printf("%lld\n",ans);
	}
	else{
		if(flag){
			ans=1;
			for(ll i=1;i<=n;i++) ans*=i,ans%=mod;
			printf("%lld\n",ans);
		}
		else{
			if(m==n){
				flag=1;
				for(int i=1;i<=n;i++){
					if(s[i]=='0'){
						flag=0;
						break;
					}
				}
				for(ll i=1;i<=n;i++) ans*=i,ans%=mod;
				if(!flag) printf("0\n");
				else printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
