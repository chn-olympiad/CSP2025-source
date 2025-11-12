#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
lo k,l,n,m,mm,r,s,ss,a[1000001],mod=998244353,b[1000001],jc[1000001];
bool vis[1000001];
string h;
lo ksm(lo x,lo y){
	lo ans=1;
	while(y){
		if(y&1)ans=ans*x%mod;
		x*=x;
		x%=mod;
		y>>=1;
	}
	return ans;
}
void dfs(lo step,lo in){
	lo i,j;
	//cout<<step<<" "<<in<<"\n";
	if(in==m){
		ss+=jc[n-step+1];
		ss%=mod;
		return ;
	}
	if(step==n+1){
		return ;
	}
	if(n-step+1<m-in)return ;
	for(i=1;i<=n;i++){
		if(!vis[i]){
			b[step]=i;
			vis[i]=true;
			if(step-1-in>=a[i]||h[step-1]=='0')dfs(step+1,in);
			else dfs(step+1,in+1);
			b[step]=0;
			vis[i]=false;
		}
	}
}
int main(){
	lo i,j;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>h;
	jc[0]=1;
	for(i=1;i<=100000;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(!a[i])r++;
	}
	//r=n-r;
	for(i=1;i<=n;i++){
		if(h[i-1]=='0')k++;
	}
	if(!k){
		//cout<<r<<"\n";
		ss=jc[n]*ksm(jc[r],mod-2)%mod*ksm(jc[n-r],mod-2)%mod;
	}
	else if(m==n){
		ss=0;
	}
	else if((n-r-k)<m){
		ss=0;
	}
	else{
		k=0;
		dfs(1,0);
	}
	printf("%lld",ss);
	return 0;
}

