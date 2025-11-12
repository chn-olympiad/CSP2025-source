#include<bits/stdc++.h>
#define cint const int
#define ll long long
#define pii pair<int,int>
using namespace std;
const ll mod=998244353;
cint N=1e3+5;
ll n,m,aans;
string s;
ll c[N],pl[N];
bool fl[N];
void dfs(int x){
	if(x==n+1){
		ll cnt=0;
		for(int j=1; j<=n; j++){
			if(n-cnt<m) break;
			if(s[j-1]=='0'){
				cnt++;
			}else{
				if(cnt>=c[pl[j]]) cnt++;
			}
		}
		if(n-cnt>=m){
			//for(int j=1; j<=n; j++) cout<<pl[j]<<' ';
			//cout<<endl;
			aans=(aans+1)%mod;
		}
		return;
	}
	for(int j=1; j<=n; j++){
		if(!fl[j]){
			pl[x]=j;
			fl[j]=1;
			dfs(x+1);
			fl[j]=0;
		}
	}
}
int main()
{
 	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int j=1; j<=n; j++) scanf("%lld",&c[j]);
	bool fl=0;
	for(int j=0; j<s.size(); j++){
		if(s[j]=='0'){
			fl=1;
			break;
		}
	}
	if(!fl){
		ll ans=1;
		for(ll j=n; j>=1; j--) ans=(ans*j)%mod;
		printf("%lld",ans);
	}else{
		if(n>11){
			printf("0");
		}else{
			dfs(1);
			printf("%lld",aans);
		}
	}
	return 0;
}

