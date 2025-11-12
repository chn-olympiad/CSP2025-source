#include<bits/stdc++.h>
using namespace std;
int a[5005];
int l[5005];
bool b[5005];
int tot;
int n;
bool check(int num) {
	int s=0,maxa=INT_MIN;
	for(int i=1; i<=num; i++) {
		s+=l[i];
	}
	for(int i=1; i<=num; i++) {
		if(l[i]>maxa)maxa=l[i];
	}
	return s>(2*maxa);
}
void dg(int s,int p,int q) {
	if(p==s+1) {
		if(check(s)==true) {
			tot++,tot%=998244353;
		}
		return;
	} else {
		for(int i=q+1; i<=n; i++) {
			l[p]=a[i];
			dg(s,p+1,i);

		}
	}
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=true;
	}
	for(int i=3; i<=n; i++) {
		dg(i,1,0);
	}
	tot%=998244353;
	cout<<tot;
}
