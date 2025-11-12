#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,flag,k;
int a[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnta,cntb;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==0&&k==0) {
		if(n<=2) cout<<1<<endl;
		else {
			if(n%2==0) cout<<n/2<<endl;
			else {
				cout<<1+(n-5)/2<<endl;
			}
		}
		return 0;
	}
	flag=0;
	for(int i=1; i<=n; i++) {
		if(a[i]>=0&&a[i]<=1) continue;
		else {
			flag=1;
			break;
		}
	}
	if(flag==0&&k==0) {
		cnta=0,cntb=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==0) cnta++;
			else if(a[i]==1) cntb++;
		}
		if(cnta%2==0&&cntb%2==0) cout<<(cnta+cntb)/2<<endl;
		else if(cnta%2==1&&cntb%2==0) cout<<1+(cnta+cntb-3)/2<<endl;
		return 0;
	} else if(flag==0&&k==1) {
		cnta=0,cntb=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==0) cnta++;
			else if(a[i]==1) cntb++;
		}
		if(cntb%2==0&&cnta%2==0) cout<<cnta/2+(cntb-cnta/2)/3<<endl;
		else cout<<cntb<<endl;
		return 0;
	}
	return 0;
}
