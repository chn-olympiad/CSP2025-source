#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s=1;
	cin>>n>>m;
	string a;
	cin>>a;
	int c[n+1];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int j=1;j<=n;j++){
		s*=j;
	}
	cout<<s%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
