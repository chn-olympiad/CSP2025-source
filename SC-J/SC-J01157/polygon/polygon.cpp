#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
const int M=998244353;
int n,a[N],ans,v[N],inv[N];
bool flag;
void dfs(int k,int sum,int ch,int mx,bool f){
	if(sum>mx*2&&ch>=3&&f==true){
		ans++;
		ans%=M;
	}
	if(k==n+1){
		return ;
	}
	dfs(k+1,sum,ch,mx,false);
	dfs(k+1,sum+a[k],ch+1,max(mx,a[k]),true);
}
int qpow(int x,int y){
	int now=1,jc=x,res=1;
	while(now<=y){
		if(y&now){
			res=res*jc%M;
		}
		now<<=1;
		jc=jc*jc%M;
	}
	return res;
}
void init(){
	v[0]=1;
	for(int i=1;i<N;i++){
		v[i]=i*v[i-1]%M;
	}
	inv[N-1]=qpow(v[N-1],M-2);
	for(int i=N-2;i>=1;i--){
		inv[i]=(i+1)*inv[i+1]%M;
	}
}
int C(int x,int y){
	return v[x]*inv[y]%M*inv[x-y]%M;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)flag=false;
	}
	if(flag==true){
		init();
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%M;
		}
		cout<<ans;
	}
	else {
		dfs(1,0,0,0,false);
		cout<<ans;
	}
	return 0;
}