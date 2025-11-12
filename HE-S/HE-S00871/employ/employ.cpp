#include<bits/stdc++.h>
using namespace std;
int n,m,a1=0,ans=0;
string s;
long long fac(int a){
	if(a==0||a==1) return 1;
	return a*fac(a-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1') a1++;
	}
	if(a1==n) ans=fac(n)%998244353;
	else if(m==n) ans=0;
	else if(m==1) ans=fac(n)%998244353;
	cout<<ans;
	return 0;
}
