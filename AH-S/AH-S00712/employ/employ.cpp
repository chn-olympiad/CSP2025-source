#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll Mod=998224353;
ll f(int n){
	if(n<1)return 1;
	return n*f(n-1)%Mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%lld\n",f(n));
	return 0;
}
