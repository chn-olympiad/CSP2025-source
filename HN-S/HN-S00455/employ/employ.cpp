#include<bits/stdc++.h>
using namespace std;
const int maxn=515,mod=998244353;
int n,m;
char p[maxn];
int c[maxn];
int jc(int k){
	int res=1;
	for(int i=k;i>k-m+1;i--){
		res*=(i%mod);
		res%=mod;
	}
	return res;
}
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)t++;
	}
	cout<<jc(n-t)<<'\n';
	
	return 0;
}
