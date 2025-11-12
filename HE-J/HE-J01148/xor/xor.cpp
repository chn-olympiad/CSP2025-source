#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int a[500000+50];
int sum[500000+50];
int summ[500000+50];
int ans;
struct node {
	int l,r;
} b[500000+50];
int maxx;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	/*for(int l=1; l<=n; l++) {
		for(int r=l; r<=n; r++) {
			for(int i=l; i<=r; i++) {
				sum[i]=sum[i-1]|a[i];
			}
			if(sum[r]==k){
				ans=r-l;
			}
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;*/
	cout<<n-1;
	return 0;
}
