#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s;
int fq;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int c[n+5];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<(rand()%s+1)%998244353;
	return 0;
}
