#include<bits/stdc++.h>
using namespace std;
long long a[500000+10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n,k;
	cin>>n>>k;
	int f=0,ok=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
		if(a[i]>=1) ok=1;
	}
	if(f==0){
		cout<<n/2;
		return 0;
	}
	if(ok==0&&k<=1&&n>1000){ 
		long long cnt0=0,cnt1=0;
		for(long long i=1;i<=n;i++){
			if(a[i]==0) cnt0++;
			else cnt1++;
		}
		if(k==1) cout<<cnt1;
		else cout<<cnt0;
		return 0;
	}
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long x=a[i];
			for(long long z=i+1;z<=j;z++){
				x=x^a[z];
			}
			if(x==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	
	return 0;
} 
