#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,sum,bo;
string s;
int c[505];
int x[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	bo=1;
	sum=1;
	for(int i=0;i<n;i++){
		x[i]=s[i]-'0';
		if(x[i]!=1){
			bo=0;
		}	
		sum=(sum*(i+1))%mod;
	}
	if(bo){
		cout<<sum;
	}
	return 0;
} 
