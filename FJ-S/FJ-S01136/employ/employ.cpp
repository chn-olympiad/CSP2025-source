#include<bits/stdc++.h>
using namespace std;
const int N=512,mod=998244353;
long long n,m,c[N],p[N],res,qz[N];string s;	//qz:前缀和 
bool f[N],A=true;
void dfs(int num){	//+8pts
	if(num==n){
		int k=0,othe=0;
		for(int i=1;i<=n;i++){
			if(qz[i-1]+othe>=c[p[i]]&&s[i]=='1')othe++;
			if(qz[i-1]+othe<c[p[i]]&&s[i]=='1')++k;
		}
		if(k>=m)res++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;p[num+1]=i;
			dfs(num+1);
			f[i]=false;p[num+1]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		qz[i]=qz[i-1];
		if(s[i]=='0')qz[i]++;
		if(s[i]=='0')A=false;
	}
	if(n<=10){
		dfs(0);
		cout<<res;
	}else if(m==n){	//+4pts
		if(A==false){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		res=1;
		for(int i=1;i<=n;i++){
			res=res*i%mod;
		}
		cout<<res;
	}else{	//+rand()%88 pts
		int cnt=0;
		for(int i=1;i<=n;i++){if(c[i]==0)cnt++;}
		if(m>n-cnt){
			cout<<0;
			return 0;
		}
	}
	return 0;
}
/*
CSP-S总结：
T1:club 100pts
T2:road 32pts
T3:replace 25pts
T4:employ 12pts
in all:169pts 
*/
