#include<bits/stdc++.h>
using namespace std;
int n,m;
string l;
int c[1000000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>l;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans; 
	return 0;
}
//KO!Ending Time Octet
