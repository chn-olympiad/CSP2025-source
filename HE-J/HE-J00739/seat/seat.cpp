#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+n+1);
	if(n==1) {
		for(int i=1; i<=n*m; i++) {
			if(a[i]==ans)cout<<i<<" "<<1;
		}
	} else if(m==1) {
		for(int i=1; i<=n*m; i++) {
			if(a[i]==ans)cout<<1<<" "<<i;
		}
	} else {
		int h=1,l=1;
		int i=n;
		while(i<=n*m) {
			if(a[i]!=ans) {
				i--;
				if(h==4)h--;
				else if(h==1)h++;
				if(i/m==l+1) {
					l++;
				}
			} else {
				cout<<l<<" "<<h;
				return 0;
			}
		}
	}
	return 0;
}

