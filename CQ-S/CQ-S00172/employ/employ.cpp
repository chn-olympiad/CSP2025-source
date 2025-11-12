//0pts-5pts?
//pian fen qwqwqwqwqwqwqwq
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%lld",(n-1)%mod*(n-2)%mod);
	return 0;
}

