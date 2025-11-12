#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
//string s1[200005],s2[200005];
ull mi[5000005];
int sl[200005];
ull sh1[200005],sh2[200005];
ull x[5000005],y[5000005];
char t1[5000005],t2[5000005];
inline void rdh(ull&hs,int&le){
	scanf("%s",t1);
	le = strlen(t1);
	for(int i = 0;i < le;i++){
		hs = hs * 13331 + t1[i];
	}
}
inline ull geh(ull*h,int l,int r){
	//printf("%llu\n",o);
	return r < l ? 0 : h[r] - h[l - 1] * mi[r - l + 1];
}
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	*mi = 1;
	for(int i = 1;i <= 5000000;i++) mi[i] = mi[i - 1] * 13331;
	for(int i = 1;i <= n;i++){
		rdh(sh1[i],sl[i]);
		rdh(sh2[i],sl[i]);
		//printf("%llu %llu\n",sh1[i],sh2[i]);
	}
	while(q--){
		scanf("%s%s",t1 + 1,t2 + 1);
		int a = strlen(t1 + 1),b = strlen(t2 + 1);
		if(a ^ b){
			puts("0");
			continue;
		}
		for(int i = 1;i <= a;i++){
			x[i] = x[i - 1] * 13331 + t1[i];
			y[i] = y[i - 1] * 13331 + t2[i];
		}
		long long ans = 0;
		for(int i = 0;i < a;i++){
			if(x[i] ^ y[i]) break;
			for(int j = 1;j <= n;j++){
				//printf("^%d\n",j);
				if(i + sl[j] > a) continue;
				ans += ((sh1[j] == geh(x,i + 1,i + sl[j])) && (sh2[j] == geh(y,i + 1,i + sl[j])) && (geh(x,i + sl[j] + 1,a) == geh(y,i + sl[j] + 1,a)));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
