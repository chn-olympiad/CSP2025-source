#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
long long p=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=m;i++){
		p=p*(n-i+1);
	}
	for(int i=1;i<=m;i++){
		p=p/(m-i+1);
	}
	
	cout<<p%998244353;
	return 0;
}
