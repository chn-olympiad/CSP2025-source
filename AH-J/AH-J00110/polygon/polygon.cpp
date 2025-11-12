#include <bits/stdc++.h>
using namespace std;
int n,a[5010],sum=0,mx=-1,cnt=0,tmpc;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=(1<<(n-1))-1;i<(1<<n);i++){
		sum=0; mx=-1; tmpc=0;
		for(int j=1;j<=n;j++)
			if(j&(i-1)){
				sum+=a[j];
				mx=max(mx,a[j]);
				tmpc++;
			}
		if(sum>2*mx && mx!=-1 && tmpc>=3) {cnt++; cnt%=998244353;}
	}
	cout<<cnt;
	return 0;
}
