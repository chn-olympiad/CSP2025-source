#include<bits/stdc++.h>
using namespace std;
int n,j=1,p;
long long k,a[500005],b[500005],s;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)scanf("%lli",&a[i]),b[i]=a[i];
	while(j<=n) {
		for(int i=1; i<=n-j+1; i++) {
			if(b[i]==k) {
				s++;
				for(int l=i; l<=i+j-1; l++)a[l]=-1,b[l]=-1;
			}
		}
		p=0;
		for(int i=1; i<=n-j; i++) {
			while(b[i]==-1)p++,i++;
			if(a[i+j]>=0)b[i]^=a[i+j];
			else b[i]=-1,p++;
		}
		if(p==n-j)break;
		j++;
	}
	cout<<s;
}
