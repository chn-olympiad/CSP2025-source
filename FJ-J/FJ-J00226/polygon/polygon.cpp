#include<bits/stdc++.h>
using namespace std;
int a[6000],n,q[6000];
int i,j;
int ma;
long long res;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(i=1;i<=n-2;i++){
		ma=max(a[i],a[i+1]);
		for(j=i+2;j<=n;j++){
			ma=max(ma,a[j]);
			if(q[j]-q[i-1]>ma*2)res=(res+1)%998244353;			
		}
	}
	cout<<res;
	return 0;
}
