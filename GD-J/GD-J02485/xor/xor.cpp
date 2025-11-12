#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N];
map<long long,int> v;
/*
4 2
2 1 0 3
*/
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	scanf("%d %lld",&n,&k);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	int end=0,ans=0;
	v[0]=0;
	for (int i=1;i<=n;i++) {
		if (v.find(s[i]^k)==v.end()) {
			v[s[i]]=i;
			continue;
		}	
		if (end<=v[s[i]^k]) {
			ans++;
			end=i;
		}
		v[s[i]]=i;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
