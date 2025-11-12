#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,x;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	cout<<2*m-x;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
