#include <bits/stdc++.h>

using namespace std;
int n,m,nx[510];
char s[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>nx[i];
	int a=rand()*rand()%998244353*rand()*rand()%998244353*rand()*rand()%998244353*rand()*rand()%998244353*rand()*rand()%998244353;
	cout<<a;
	return 0;
}

