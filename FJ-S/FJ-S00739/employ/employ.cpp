#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long a=1;
	string s1;
	cin>>n>>m;
	int x=n;
	int c[n];
	cin>>s1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=x;i++){
		a*=i;
		a%=998244353;
	}
	cout<<a;
	return 0;
}

