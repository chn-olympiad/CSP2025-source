#include<iostream>
#define ll long long
using namespace std;
const int N=5e5+10;
ll xr(ll x,ll y){
	return x xor y;
}
int n,k,a[N];
int tol=0;
void dfs(int u,int ii,ll val,int nt){
//	cout<<u<<' '<<ii<<' '<<val<<' '<<nt<<endl;
	if(ii>n){
		tol=max(tol,nt);
		return;
	}
	ll rx=xr(val,1ll*a[ii]);
	if(u==1)rx=a[ii];
	dfs(u+1,ii+1,rx,nt);
	if(a[ii]==k)nt++;//,cout<<ii<<" ";
	if(val==k)nt++;//,cout<<val<<" ";
	dfs(1,ii+1,-1,nt);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int va1=0,va0=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)va1++;
		else if(a[i]==0)va0++;
	}
	if(va1==n){
		if(k>1)cout<<0;
		else if(k==1)cout<<n;
		else if(k==0)cout<<n/2;
		return 0;
	}
	else if(va1+va0==n){
		if(k>1)cout<<0;
		else if(k==1)cout<<va1;
		else if(k==0){
			int ans=va0,now=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){now++;continue;}
				ans+=now/2;
				now=0;
			}
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
	}
	dfs(1,1,-1,0);
	cout<<tol;
	return 0;
}
