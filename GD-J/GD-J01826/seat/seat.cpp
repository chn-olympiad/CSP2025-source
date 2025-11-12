#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],s;
bool cmp(int n,int m) {
	return n>m;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int d=n*m;
	for(int i=1; i<=d; i++) {
		cin>>a[i];
		if(i==1)s=a[i];
	}
	sort(a+1,a+d+1,cmp);
	int cnt1=0,cnt2;
	for(int i=1; i<=d; i++) {
		if(a[i]==s) {
			cnt2=i;
			break;
		}
	}
	for(int j=1; j<=m; j++) {
		for(int i=1; i<=n; i++) {
			cnt1++;
			if(cnt1==cnt2) {
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
		j++;
		for(int i=n; i>=1; i--) {
			cnt1++;
			if(cnt1==cnt2) {
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
