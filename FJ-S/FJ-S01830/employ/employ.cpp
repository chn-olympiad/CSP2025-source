#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int ans=1;
int c[500];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int s=n-1;
	while(s--){
		ans=ans*s;
	}
	ans=ans*n;
	int l=ans%998244353;
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
