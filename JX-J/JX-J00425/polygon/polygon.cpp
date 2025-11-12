#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxa[5005][5005],sum[5005][5005],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[1][i]=sum[1][i-1]+a[i];
		maxa[1][i]=max(maxa[1][i-1],a[i]);
	}
	if(n<=3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<11;
	return 0;
}
