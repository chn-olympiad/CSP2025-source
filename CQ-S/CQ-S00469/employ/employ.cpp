#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans,n,m,c[509],lg,f[509][509],kl;
string s;
bool p[509],pl;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++){
		p[i+1]=s[i]-'0';
		if(s[i]-'0'==1)kl++;
		if(p[i+1]==0)pl=1;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0)lg++;
	}
	if(pl==0)cout<<"1";
	else cout<<"0";
	return 0;
} 
