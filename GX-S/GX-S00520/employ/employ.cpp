#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string a;
	int n,m,n1=1,n2=1,mn3=1,mn4=0;
	cin>>n>>m;
	cin>>a;
	int s[n+9];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		n1=n1*i;
	}
	for(int i=1;i<=m;i++){
		n2=n2*i;
	}
	for(int i=1;i<=n-m;i++){
		mn3=mn3*i;
	}
	mn4=n2*mn3;
	mn4=n1/mn4;
	cout<<mn4%998244353;
return 0;
}
