#include<bits/stdc++.h>
using namespace std;
int st[5005];
int n;
long long cnt;
void search(int i,int step,int mxn,int tot,int pe) {
	if(step==i&&mxn*2<tot) {
		cnt=(cnt+1)%998244353;
	} else {
		for(int j=pe+1; j<=n; j++) {
			int mxn1=max(mxn,st[j]);
			int tot1=tot+st[j];
			if(step<i-1) {
				search(i,step+1,mxn1,tot1,j);
			} else if(mxn1*2<tot1) {
				search(i,step+1,mxn1,tot1,j);
			} else {
				break;
			}
		}
	}
	return ;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>st[i];
	}
	sort(st+1,st+n+1);
	for(int i=3; i<=n; i++) {
		search(i,0,0,0,0);

	}
	cout<<cnt;
	return 0;
}


