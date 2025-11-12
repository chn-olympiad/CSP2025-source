#include<bits\stdc++.h>
using namespace std;

int s[105];
int n,m;

int h(int a,int b) {
	return a>b;
}

int hs(int r) {
	int t=0;
	for (int i=1;i<=m;i++) {
		if (i%2==1) {
			for (int j=1;j<=n;j++) {
				t++;
				if (t==r) {
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
		else {
			for (int j=n;j>=1;j--) {
				t++;
				if (t==r) {
					cout<<i<<' '<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int r;
	cin>>n>>m;
	cin>>r;
	s[1]=r;
	for (int i=2;i<=n*m;i++) {
		cin>>s[i];
	}
	sort(s+1,s+n*m+1,h);
	for (int i=1;i<=m*n;i++) {
		if (s[i]==r) {
			r=i;//r变成下标
			break;
		}
	}
	hs(r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}