#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
int n,m;
string s;
int c[N];
long long d;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	d=1;
	for(int i=1;i<=n;i++){
		d=(d*n)%998244353;
	}
	printf("%lld",d);
	return 0;
}
