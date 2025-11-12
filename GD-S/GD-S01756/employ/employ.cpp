#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1010,mod=998244353;
ll n,m,c[N],ans=0ll,k=0ll,cnt0[N],ind[N];
bool st[N];
string s;
void dfs(ll u,ll deep,ll unpass){
	st[u]=1;
	if(deep>=n){
		if((n-unpass)>=m){
			ans++;
			ans%=mod;
		
		}
		st[u]=0;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(st[i]) continue;
		if(unpass<c[i]&&s[deep]=='1'){
			dfs(i,deep+1,unpass);

		}else{

			dfs(i,deep+1,unpass+1);
		}
			
	}st[u]=0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(ll i=0;s[i];i++){
		if(s[i]=='0'){
			cnt0[i]=cnt0[i-1]+1;
		}else{
			cnt0[i]=cnt0[i-1];
		}ind[cnt0[i]]=i;
		
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",c+i);
		if(c[i])
			k++;
	}//sort(c+1,c+1+n);
	if(1){
		dfs(0,0,0);
		printf("%lld\n",(ans)%mod);
		return 0;
	}else{
		if(m==n){
		ans++;
		for(ll i=0;s[i];i++){
			if(s[i]=='0'){
				printf("0");
				return 0;
			}
		}if(c[1]==0){
			printf("0");
			return 0;
		}else{
			for(ll i=1;i<=n;i++)
				ans*=i;
			printf("%lld\n",ans);
			return 0; 
		}
	}else if(m==1){
		ans++;
		if(ind[c[n]-1]=='1'){
			for(ll i=1;i<n;i++)
				ans=ans*i%mod;
			printf("%lld\n",ans);
		}return 0;
		
	}ans++; 
	for(ll i=1;i<=k;i++){
		
		ans=ans*i;
	}printf("%lld",ans%mod);
	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

