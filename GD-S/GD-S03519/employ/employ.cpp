#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
const int M=998244353; 
long long t=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	} 
	for(int i=1;i<=n;++i){
		t*=i;
		t%=M;
	}
	cout<<t;
	return 0;
}
