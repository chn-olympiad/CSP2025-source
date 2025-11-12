#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],maxn=0,sum,ci,cn=1,out;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(maxn==1){
		for(int i=1;i<=n;i++){
			cn*=i;
			cn=((cn%998)%244)%353;
		}
		for(int i=3;i<=n;i++){
			ci=1;
			for(int j=1;j<=i;j++){
				ci*=j;
				ci=((ci%998)%244)%353; 
			}
			out+=cn/ci;
			out=((out%998)%244)%353;
		}
		cout<<out;
	}
	return 0;
}