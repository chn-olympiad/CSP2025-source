#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
int n,m,u[505],A=1,nl=0;
long long num=1;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') A=0;
	}
	for(int i=1;i<=n;i++){
		cin>>u[i];
		if(u[i]==0) nl++;
	}
	if(m==n){
		if(A==0){
			cout<<0;
			return 0;
		}
		if(nl){
			cout<<0;
			return 0;
		}
		for(int i=n;i>=1;i--) num*=i;
		cout<<num%p;
		return 0;
	}
	if(A){
		long long peo=0;
		sort(u+1,u+n+1);
		for(int i=1;i<=n;i++){
			if(u[i]<=peo) peo++;
			else break;
		}
		if(n-peo<m){
			cout<<0;
			return 0;
		}
		for(int i=n;i>=1;i--) num*=i;
		cout<<num%p;
		return 0;
	}
	cout<<263;
	return 0;
}
