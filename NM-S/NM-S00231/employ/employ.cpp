#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;

int n,m,a;
string s;
unsigned long long res;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a;
		res=(res+a+m)%mod;
		if(a)res=res*a*m%mod;
	}
	cout<<res<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
