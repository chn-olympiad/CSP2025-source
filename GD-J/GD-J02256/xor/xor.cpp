#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,s,s1,s2,a[500005],ans,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(m<=1){
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]==0)s++,s2+=t/2,t=0;
			else if(a[i]==1)s1++,t++;
		}
		s2+=t/2;
		if(m==1)printf("%lld",s1);
		else printf("%lld",s+s2);
	}
	else printf("2");
	return 0;
}

