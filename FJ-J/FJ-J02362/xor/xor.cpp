#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ok=1;
	int cnt1=0,cnt0=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)ok=0;
		if(a[i]==1)cnt1++;
		if(a[i]==0)cnt0++;
	}
	if(ok==1&&k==0)cout<<n/2;
	else if(ok==1&&k==1)cout<<n;
	else{
		if(k==1)cout<<cnt1;
		else if(k==0)cout<<cnt0;
		else{
			for(int i=0;i<n;i++){
				sum[0]=a[0];
				if(i>0)sum[i]=(sum[i-1]^a[i]);
			}
			int ret=0;
			for(int i=0;i<n;i++){
				if(sum[i]==k)ret++;
				if(a[i]==k)ret++;
			}
			cout<<ret;
		}
	}
	return 0;	
}
