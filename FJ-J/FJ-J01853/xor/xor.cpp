#include<bits/stdc++.h>
using namespace std;
int a[500100];
long long n,k;
struct ac {
	int ll,rr;
} q[1000100];
int cnt=0;
bool cmp(ac qq,ac ww){
	return qq.rr<ww.rr;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}

	long long sum;
	for(int r=1; r<=n; r++) {

		for(int l=r; l>=1; l--) {
			if(l==r) {
				sum=a[r];
			} else {
				sum^=a[l];
			}
			if(sum==k) {
				q[++cnt].ll=l;
				q[cnt].rr=r;
				
			}
		}
	}
	sort(q+1,q+1+cnt,cmp);
	long long CNT=0;
	int ro=0;
    for(int i=1;i<=cnt;i++){
    	if(i==1) CNT++,ro=q[i].rr;
    	else if(q[i].ll>ro) CNT++,ro=q[i].rr;
	}
	cout<<CNT;
	return 0;
}
