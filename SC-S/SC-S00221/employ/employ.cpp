#include<bits/stdc++.h>
using namespace std;
int m,n;
//set<int>f;
long long ans=1;
string s;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	cin>>s;
	
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		//f.insert(x);
	}
	for(int i=1;i<=m;i++)ans=(ans*(i%mod))%mod;
	cout<<ans;
	 
	return 0;
	}
	