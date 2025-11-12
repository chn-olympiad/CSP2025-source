#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],c[500005],l,cnt;
bool pd;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		b[i]=(b[i-1]^a[i]);
		c[i]=c[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		pd=0;
		for(long long j=l+1;j<=i && !pd;j++){
			if(c[i]-c[j-1]<k) break;
			if((b[i]^b[j-1])==k) pd=1;
		}
		if(pd) cnt++,l=i;
	}
	cout<<cnt<<"\n";
	return 0;
}

