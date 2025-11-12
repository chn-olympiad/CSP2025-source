#include<bits/stdc++.h>
using namespace std;
int mod=998244353;
int t,n,m,p[1001];
int ks[1001];
long long jx(int n){
	long long ans=1;
	while(n>=2)
	ans*=n,ans%=mod,n--;
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int lp=n;
	char ss;
	for(int i=1;i<=n;i++){
		cin>>ss;
		ks[i]= ss=='0'? 0 : 1;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]==0)lp--;
	}
	if(lp<m)cout<<"0";
	else cout<<jx(n);
	return 0;
}