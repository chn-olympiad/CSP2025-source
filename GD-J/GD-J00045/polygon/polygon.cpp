#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353,N=5005;
int n,a[N],b[N],cnt;
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]+b[i-1];
	}
		int sum=0,ma=0;
		for(int i=1;i<=n;i++){
			ma=max(a[i],ma);
			sum+=a[i];
		}
	if(n==3){
		if(sum>ma*2)cnt++;
	}
	cout<<cnt%Mod;
	return 0;
} 
