#include<bits/stdc++.h>
using namespace std;
int n,m,b[505],ans=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out"."w",stdout);
	scanf("%d%d",&n,&m);
	cin >> a;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	printf("%d",ans);
}
