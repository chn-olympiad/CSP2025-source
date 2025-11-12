/*AK CSP-J*/
#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,k,sum[N],c;
struct ys{
	long long l,r;
}a[N];
bool cmp(ys x,ys y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		long long t;
		cin>>t;
		sum[i]=sum[i-1]^t;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long t=abs(sum[j]^sum[i-1]);
			if(t==k){
				a[++c].l=i;
				a[c].r=j;
			}
		}
	}sort(a+1,a+c+1,cmp);
	long long R=a[1].r,ans=1;
	for(int i=2;i<=c;i++){
		if(R<a[i].l){
			R=a[i].r;
			ans++;
		}
	}cout<<ans;
	return 0;
}
