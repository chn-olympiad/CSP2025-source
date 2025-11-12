#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N],n,k,ans;
int lrxor(int l,int r) {
	if(l==r) {
		return a[l];
	}
	int x=a[l];
	for(int i=l+1;i<=r;i++) {
		x=x^a[i];
	}
	return x;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int l=1;l<=n;l++) {
		for(int i=1;i<=n;) {
			int anst=0;
			for(int j=i;j<=n;j++) {
				if(lrxor(i,j)==k) {
					anst++;
					i=j+1;
				}
			}
			i++;
			ans=max(ans,anst);
		}
	}
	cout<<ans<<endl;
	return 0;
}