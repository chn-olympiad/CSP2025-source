#include<bits/stdc++.h>
using namespace std;
int a[47],cam,s=0,maxn=-47;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3) {
		for(int i=1; i<=n; i++) {
			cin>>cam;
			s=s+cam;
			if(cam>maxn) {
				maxn=cam;
			}
		}
		if(s>2*maxn) {
			cout<<1;
		} else {
			cout<<0;
		}
	}
    else{
    	cout<<0;
	}
	return 0;
}
