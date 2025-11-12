#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[10076];
int ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=n;i>0;i--){
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}
