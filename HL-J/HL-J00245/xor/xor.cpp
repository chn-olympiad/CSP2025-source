#include <iostream>
#include <cstdio>
using namespace std;
int a[500005];
int b[500005];
bool c[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%d",&a[1]);
	b[0] = 0;
	b[1]=a[1];
	int maxn=-1;
	for (int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		maxn = max(maxn,a[i]);
		b[i]=b[i-1]^a[i];
	}
	if (maxn==1){
		if (k==0){
			int ans=0;
			for (int i=1;i<=n;i++){
				if (a[i]==0) ans++;
				else if (a[i]==1&&a[i+1]==1){
					ans++;i++;
				}
			}
			cout << ans;
			return 0;
		}else if (k==1){
			int ans=0;
			for (int i=1;i<=n;i++){
				if (a[i]==1) ans++;
			}
			cout << ans;
			return 0;
		}
	}
	long long ans=0;
	for (int i=1;i<=n;i++){
		int l=1,r=i;
		Before:
		for (int g=l;g<=r;g++){
			if (c[g]){
				l=g+1;
				r=g+i;
				goto Before;
			}
		}
		for (;r<=n;l++,r++){
			if (c[r]){
				l=r+1;
				r=l+i-1;
				continue;
			}
			if (int(b[r]^b[l-1])==k){
				ans++;
//				cout << l << " " <<r << " " << b[r] << b[l-1]  << " " << k<< endl;
//				cout << int(2^0) << endl;
				for (int ll=l;ll<=r;ll++) c[ll]=1;
				l=r+1;r=l+i-1;
			}
		}
	}
	cout << ans;
    return 0;
}
