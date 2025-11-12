#include<bits/stdc++.h>
using namespace std;
int nx[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string b;
	cin>>b;
	for(int i=1;i<=n;i++){
	cin>>nx[i];	
	}
	int a; 
	a=n*(n-1);
	 a=a%998;
	 a=a%244;
	 a=a%353;
	 cout<<a;
	return 0;
}
