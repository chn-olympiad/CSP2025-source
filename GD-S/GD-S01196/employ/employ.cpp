#include<bits/stdc++.h>
using namespace std;
#define read(r1,r2) freopen(r1,"r",stdin);freopen(r2,"w",stdout);
const int mod=998244353;
int n,m,a[505],s[505],g[505],x,f,cnt,jc[505],sum99,vis[15],sta[15],xxx[505];
char c;
long long cnt2=1,ans;
void init(){
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;sum%=mod;
		jc[i]=sum;
	}
}
void dfs(int id){
	if(id==n+1){
		int summ=0,cntt=0;
		for(int i=1;i<=n;i++){
			if(xxx[sta[i]]>=i&&a[i]==1)cntt++;
		}
		if(cntt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			sta[id]=i;
			dfs(id+1);
			vis[i]=0;
		}
	}
}
int main(){
	read("employ.in","employ.out")
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[i]=c-'0';
		if(a[i]==0)f=1;
	}
	for(int i=1;i<=n;i++){
		cin>>x;if(x==0)sum99++;
		for(int j=1;j<=x;j++){
			g[j]++;
		}
		xxx[i]=x;
	}
	init();
	if(sum99>n-m){
		cout<<0<<endl;
		return 0;
	}
	if(m==1){
		cnt2=1;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans+=jc[n-cnt-1]*g[i]*cnt2;
				ans%=mod;
				cnt2=cnt2*(n-g[i]-cnt)%mod;
				cnt++;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(f==0){
		if(sum99<=n-m)cout<<jc[n]<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(m==n){
		if(f==1){
			cout<<0<<endl;
			return 0;
		}
		else{
			if(sum99>0){
				cout<<0<<endl;
				return 0;
			}
			else{
				cout<<jc[n]<<endl;
				return 0;
			}
		}
	}
	else{
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
}
