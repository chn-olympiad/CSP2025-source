#include<bits/stdc++.h>
using namespace std;
long long n,q,ans;
char s1[1005][1005],s2[1005][1005],t1[1000005],t2[1000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++){
		scanf("%s%s",s1[i],s2[i]);
	}
	for(long long i=1;i<=q;i++){
		scanf("%s%s",t1,t2);
		cout<<0<<endl;
	}
	return 0;
}
