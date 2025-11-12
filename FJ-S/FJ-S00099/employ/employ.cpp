#include<bits/stdc++.h>
using namespace std;
char a[10000];
int as[100000];
int main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long s;
	scanf("%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>as[i];
	}
		s=1;
		for(int i=1;i<=n;i++){
			s=s*i%998244353;
		}
		printf("%lld",s);
	return 0;
}
