#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
} 
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
ll n,m,ans=0;
ll c[1050],p[1050],b[1050];
char ch[1050];
ll jie[1050];
void dfs(ll d,ll sum,ll k){
	if(sum==m){
		ans=(ans%mod+jie[n-d+1])%mod;
		return;
	}
	if(d>n) return;
	for(ll i=1;i<=n;++i){
		if(!b[i]){
			if(p[d]==1&&k<c[i]){
				b[i]=1;
				dfs(d+1,sum+1,k);
				b[i]=0;
			}
			else{
				b[i]=1;
				dfs(d+1,sum,k+1);
				b[i]=0;
			}
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>ch;
	jie[0]=1;
	for(ll i=0;i<n;++i) p[i+1]=ch[i]-'0';
	for(ll i=1;i<=n;++i) c[i]=read(),jie[i]=jie[i-1]*i%mod;
	dfs(1,0,0);
	cout<<ans%mod<<endl;
	return 0;
}
/*
世界全剧终 我们新艾利都见 
*/
