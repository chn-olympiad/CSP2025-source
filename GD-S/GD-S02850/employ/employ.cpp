#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
long long jc(int x){
	if(x<2)return 1;
	return (jc(x-1)%MOD) * (x%MOD); 
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	for(int i=0;i<n;++i)cin>>t;
	cout<<jc(n)%MOD;
	
	
 return 0;
}
