#include<bits/stdc++.h>
using namespace std;
const int N=10007,MOD=998244353;
int n,a[N],maxn;
long long res,s[N],steps[N]={1,1},asteps[N]={0,1};

void dfs(int last,int maxn,long long sum,int l){
	if(l>=3)	res+=(sum>maxn*2);
	for(int i=last-1;i>0;i--){
		if(s[i]+sum<=maxn*2)	break;
		dfs(i,max(a[i],maxn),sum+a[i],l+1);
	}
}long long qpow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1)	res*=a,res%=MOD;
		a*=a,a%=MOD,b>>=1;
	}return res;
}long long C(long long a,long long b){
	if(a==b)	return 1;
	return (steps[a]*asteps[b]%MOD*asteps[a-b]%MOD);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i],maxn=max(a[i],maxn);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	s[i]=s[i-1]+a[i];
	
if(n<29){
//
	dfs(n+1,0,0,0);
	cout<<res%MOD<<endl;
//
}else if(maxn==1){
//
	for(int i=2;i<=n;i++)	steps[i]=steps[i-1]*i,steps[i]%=MOD,asteps[i]=asteps[i-1]*qpow(i,MOD-2),asteps[i]%=MOD;
	long long res=0;
	for(int b=3;b<=n;b++)	res+=C(n,b),res%=MOD;
	cout<<res<<endl;
	
//		
}else{
//
//	
}
	
	fclose(stdin);
	fclose(stdout);
}/*
CICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICI
CICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICICI
*/
