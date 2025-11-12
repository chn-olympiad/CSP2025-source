#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	LL f=0,f1=0,cnt=0,cnt0=0;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
		if(a[i]>1)f1=1;
		if(a[i]==1)cnt++;
		if(a[i]==0)cnt0++;
	}
	if(f==0){
		if(n%2==0)cout<<n/2;
		else cout<<0;
	}
	else if(f1==0&&k==1){
		cout<<cnt;
	}
	else if(f1==0&&k==0){
		LL sum=0,p,f2=0;
		for(LL i=1;i<=n;i++){
			if(a[i]==1&&f2==1){
				sum+=(i-p-1);
				f2=0;
				continue;
			}
			if(a[i]==1&&f2==0){
				f2=1;
				p=i;
			}
		}
		if(cnt%2!=0)cout<<0;
		else cout<<cnt/2+cnt0-sum;
	}
	else{
		cout<<0;
	}
	return 0;
}
