#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=550,mod=998244353;
int qpow(int x,int k){
	if(k==0)return 1;
	if(k==1)return x;
	int r=qpow(x,k>>1);
	r=r*r%mod;
	if(k%2)r=r*x%mod;
	return r;
}
int n,m;
char s[M];
int a[M];
bool ps=true;
bool pd[M];
int ans=0;
void dfs(int u,int hs){
	if(hs>n-m)return;
	if(u==n+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(pd[i])continue;
		pd[i]=true;
		if(hs>=a[i]||s[u]=='0')dfs(u+1,hs+1);
		else dfs(u+1,hs);
		pd[i]=false;
	}
} 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int p1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			ps=false;
		}else{
			p1++;
		}
	}
	int ys=n;
	for(int i=1;i<=n;i++){
		if(a[i]==0)ys--;
	}
//	cout<<"ys:"<<ys<<endl;
	if(min(ys,p1)<m){
		cout<<0<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
}
