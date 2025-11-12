#include <bits/stdc++.h>
using namespace std;
int const N=5e5+5;
int n;
long long k,ans;
struct node {
	int v;
	bool flag=false;
}a[N];
bool f(int l,int r) {
	int p=a[l].v^a[l+1].v;
	for(int i=l+2;i<=r;i++) {
		p=p^a[i].v;
	}
	if(p==k) {
		return true;
	}
	return false;
}
bool b(int le,int ri) {
	for(int i=le;i<=ri;i++) {
		if(a[i].flag) {
			return false;
		}
	}
	return true;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i].v);
	}
	for(int i=1;i<=n;i++) {
		if(a[i].v==k) {
			a[i].flag=true;
			ans++;
		}
	}
	for(int len=2;len<=n;len++) {
		for(int i=1;i<=n-len+1;i++) {
			if(b(i,i+len-1)==false) {
				continue;
			}else {
				if(f(i,i+len-1)) {
					for(int t=i;t<=i+len-1;t++) {
						a[t].flag=true;
					}
					ans++;
				}
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
