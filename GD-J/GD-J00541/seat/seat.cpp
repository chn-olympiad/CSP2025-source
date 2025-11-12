#include<bits/stdc++.h>
using namespace std;

int n,m,p,k,a[105],c[105][105];
bool cmp(int a,int b) {
	return a>b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int len=n*m;
	for(int i=1; i<=len; i++) {
		cin>>a[i];
		if(i==1) p=a[i];
	}
	k++;
	bool f=0;
	sort(a+1,a+len+1,cmp);
	for(int j=1; j<=m; j++) {

		int l=0,r=0;
		if(j%2!=0) l=1,r=n;
		else l=n,r=1;

		for(int i=l; j%2!=0?i<=r:i>=r; j%2!=0?i++:i--) {
			if(a[k]==p) {
				cout<<j<<' '<<i;
				f=1;
				break;
			} else {
				c[j][i]=a[k];
				k++;
			}
		}
		if(f==1) {
			break;
		}

	}

	return 0;
}

