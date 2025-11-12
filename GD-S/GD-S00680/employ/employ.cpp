#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long p=1;
int n,m,c[510];
string s;
bool b=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]==0){
			b=0;
			break;
		}
	}
	if(b){
		for(int i=n;i>=1;i--){
			p*=i;
			p%=MOD;
		}
		cout<<p;
		return 0;
	}
	cout<<0;
	return 0;
} 
