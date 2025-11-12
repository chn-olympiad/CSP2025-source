#include<bits/stdc++.h>
using namespace std;
long long a[1000001],n,m=1,s2=0,mod = 998244353,ko,l,j=1;
string s[100001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout);
	cin>>n>>m;
	for(int i = n;i>=1;i--){
		cin>>s[i];
		if(s[i]=='0'){
			ko++;
		}
		if(s[i]=='1'){
			s2=i;
		}
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=s2){
			l++;
		}
	}
	if(s2!=0){
		for(int i = 1;i<=n-l;i++){
			j=(j%mod*i)%mod;
		}
		cout<<l*j%mod;
	}
	return 0;
} 
