#include<bits/stdc++.h>
using namespace std;
int t,n;
struct manyidu {
	int a,b,c;
} a[252525];
bool cmp(manyidu apl,manyidu bpl) {
	return apl.a>bpl.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		bool flag=true,flagsecond=true;
		scanf("%d",&n);
		int p=n/2;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].c||a[i].b)flag=false;
		}
		if(flag) {
			long long sum=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1; i<=p; i++) {
				sum+=a[i].a;
			}
			cout<<sum;
		}
		else if(n==2) {
			int maxmanyi=INT_MIN;
			maxmanyi=max(maxmanyi,a[1].a+a[2].b);
			maxmanyi=max(maxmanyi,a[1].a+a[2].c);
			maxmanyi=max(maxmanyi,a[1].b+a[2].c);
			maxmanyi=max(maxmanyi,a[1].b+a[2].a);
			maxmanyi=max(maxmanyi,a[1].c+a[2].a);
			maxmanyi=max(maxmanyi,a[1].c+a[2].b);
			cout<<maxmanyi;
		}
		else{
			long long sum=0;
			for(int i=1; i<=n; i++){
				sum+=max(a[i].a,max(a[i].b,a[i].c));
			}
			cout<<sum;	
		}
		cout<<endl;
	}
	return 0;
}