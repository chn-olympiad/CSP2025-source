#include<bits/stdc++.h>
using namespace std;
int a[5005],n;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=7;i<pow(2,n);i++){
		long long j=i,cnt=0,h=0,t=0,maax=0;
		while(j){
			if(j&1){
				cnt++;
				h+=a[n-t];
				if(maax==0)maax=a[n-t];}
			t++;j=j>>1;}
		if(t>=3&&h>2*maax){
			ans=(ans+1)%998244353;}}
	cout<<ans;
	return 0;}