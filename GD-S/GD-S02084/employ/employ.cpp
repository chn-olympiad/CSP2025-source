#include<bits/stdc++.h>
using namespace std;
long long n,m,s[505],c[505],B=18,u=0;
bool A=1,ck[15];
long long qj(long long dat,long long fai) {
//	cout<<dat<<','<<fai<<endl;
//	cout<<ck[1]<<ck[2]<<ck[3]<<endl;
	if(dat>=n)return (fai+m<=n);
	if(fai+m>n)return 0;
	long long ans=0;
	for(long long i=1; i<=n; i++) {
		if(ck[i])continue;
		ck[i]=1;
		if(fai>=c[i]||s[dat+1]==0) {
			if(fai+m<n)
			ans+=qj(dat+1,fai+1);

		} else {

			ans+=qj(dat+1,fai);

		}
		ck[i]=0;
		ans=ans%998244353;
	}
	return ans;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	for(long long i=1; i<=n; i++) {
		char ch;
		cin>>ch;
//		cout<<ch<<endl;
		s[i]=ch-'0';
		if(s[i]!=1)A=0;
		else B--;
	}
	for(long long i=1; i<=n; i++) {
		cin>>c[i];
	}
	if(n<=12) {
		cout<<qj(0,0)<<endl;
		return 0;
	}
	if(B&&m+B>18){
		cout<<'0'<<endl;
		return 0;
	}
	if(A){
		long long tmp=1;
		for(long long i=1;i<=n;i++){
			tmp=tmp%998244353;
			tmp=tmp*i;
		}tmp=tmp%998244353;
		cout<<tmp;
	}
	return 0;
}
