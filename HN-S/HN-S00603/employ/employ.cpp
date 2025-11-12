#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,c[505],g;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	g=n;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
		if(c[i]==0) g--;
	}
	int sum=1;
	for(int i=1;i<=g;i++){
		sum*=i;
		sum%=mod;
	}
	cout<<sum;
	return 0;
}

