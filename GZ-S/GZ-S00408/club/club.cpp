//GZ-S00408   许家琪    遵义市第四中学
#include<bits/stdc++.h>
using namespace std;
int zs,n,a1,a2,a3;
struct aa {
	int a1;
	int a2;
	int a3;
};
void cmp(int x,int y) {
	if(x<y) {
		return y,x;
	} else {
		return x,y;
	}
}
int main() {
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	cin>>zs;
	aa a[1000001];
	for(int i=1; i<=zs; i++) {
		cin>>n;
		for(int j=1; j<=n; j++) {
			cin>>a[i].a1;
			cin>>a[i].a2;
			cin>>a[i].a3;
		}
	}
	sort(a+1,a+n+1);
	for(int i=i; i<=n; i++){
		
	}
		return 0;
}
