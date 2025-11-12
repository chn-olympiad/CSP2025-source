#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long s=1;
	int n;
	cin>>n;
	int m,c;
	string b;
	cin>>m;
	cin>>b;
	for(int i=1;i<=n;i++){
		cin>>c;
	}
	for(int i=1;i<=n;i++){
		s*=i;
		s=s%998244353;
	}
	cout<<s;
	return 0;
}