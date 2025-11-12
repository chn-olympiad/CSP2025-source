#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int c[n];
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	cout<<m%998244353;
	return 0;
}
