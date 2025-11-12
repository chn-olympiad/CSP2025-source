#include<bits/stdc++.h>
using namespace std;
const long long N=1000,M=998244353;
long long n,m,c[N+5],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long j1=0;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			j1++;
		}
	} 
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(j1==n){
		for(int i=1;i<=j1;i++){
			ans%=M;
			ans*=i;
		}
	}
	cout<<ans%M;
	return 0;
	
}
