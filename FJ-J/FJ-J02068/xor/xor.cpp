#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[7891];
int f(int n,int m) {
	int b[25]= {0};
	int i=1;
	while(n!=0) {
		b[i]=n%2;
		n/=2;
		i++;
	}
	int j=1;
	while(m!=0) {
		if(m%2==1&&b[j]==1)b[j]=0;
		if(m%2==1&&b[j]==0)b[j]=1;
		m/=2;
		j++;
	}
	int k=0;
	for(int l=1,h=1; l<=24; l++,h*=2) {
		k+=b[l]*h;
	}
	return k;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1,ii=1; i<=n; ii++,i++) {
		int k;
		cin>>k;
		a[ii]=k;
		for(int j=1; j<=ii; j++) {
			if(f(a[j],k)==m) {
				ans++;
				ii=1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

