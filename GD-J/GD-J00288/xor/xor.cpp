#include<bits/stdc++.h>
using namespace std;
int yihuohe(int a,int b) {
	int _a[100000];
	int _b[100000];
	int c[100000];
	int p=1,q=1;
	while(a) {
		int e=a%2;
		_a[p++]=e;
		a/=2;
	}
	while(b) {
		int _i=b%2;
		_b[q++]=_i;
		b/=2;
	}
	int k=max(p,q);
	if(k==p) {
		for(int i=1; i<=p; i++) {
			c[i]=_a[i];
		}
		for(int i=1; i<=q; i++) {
			if(c[i]!=_b[i])c[i]=1;
			else c[i]=0;
		}
	} else {
		for(int i=1; i<=q; i++) {
			c[i]=_b[i];
		}
		for(int i=1; i<=p; i++) {
			if(c[i]!=_a[i])c[i]=1;
			else c[i]=0;
		}
	}
	int sum=0;
	for(int i=1; i<=k; i++) {
		sum+=pow(2,i-1)*c[i];
	}
	return sum;
}
int a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int num=1;
	cin>>n>>k;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++) {
		long long tot=0;
		for(int j=i+1; j<=n; j++) {
			tot+=yihuohe(a[j],a[j-1]);
			if(tot==k) {
				num++;
				i=j+1;
				break;
			}
		}
	}
	cout<<num;
}
