#include<bits/stdc++.h>
using namespace std;
int n,s,z=1,m=998244353,a[5000],d[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n),s=n;
	for(int i=0;i<n;i++){
		for(int j=5000-a[i];j>a[i];j--) d[j+a[i]]=(d[j+a[i]]+d[j])%m;
		for(int j=a[i];j>5000-a[i];j--) s=(s+d[j])%m;
		for(int j=min(a[i],5000-a[i])+1;j--;s=(s+d[j])%m,d[j+a[i]]=(d[j+a[i]]+d[j])%m);
		d[a[i]]++;
	}
	while(n--) z=z*2%m;
	printf("%d",((z-1+m)%m-s+m)%m);
	return 0;
}
