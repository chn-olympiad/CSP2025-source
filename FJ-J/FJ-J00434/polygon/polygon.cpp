#include<bits/stdc++.h>
using namespace std;
long long n,s=0,a[5005],maxs=-1,tot=0,ans=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	s=s/2;
	sort(a+1,a+n+1,cmp);
	long long j=0;
	tot=s+1;
	for(long long m=3;m<=n;m++){
		while(tot>=s){
		tot=0;
		j++;
		for(long long i=j;i<=m;i++){
			tot+=a[i];
		}
	}
	}
	if(j!=1)cout<<(j*3)%998224353;
	else cout<<0;
	return 0;
}
