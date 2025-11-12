#include <bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
struct yihuo{
	int nl;
	int nr;
}so[5000005];

bool cmp(yihuo x,yihuo y){
	return x.nr<y.nr;
}

int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
	}
	int ans=0,x=1;
	for (int l=1;l<=n;l++){
		for (int r=l;r<=n;r++){
			if ((sum[r]^sum[l-1])==k){
				ans++,so[x].nl=l,so[x].nr=r,x++;
			}
		}
	}
	sort(so+1,so+ans+1,cmp);
	int dr=so[1].nr,sum=1;
	for (int i=2;i<=ans;i++){
		if (so[i].nl>dr) sum++,dr=so[i].nr;
	}
	cout<<sum;
	return 0;
}
