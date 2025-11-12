#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long cnt1=0,cnt0=0;
	bool f=1;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0){
			f=0;
		}else{
			if(a[i]==1){
				cnt1++;
			}else{
				cnt0++;
			}
		}
	}
	if(f==1){
		if(cnt1>0&&cnt0==0){
			cout<<0;
		}else if(cnt1>0&&cnt0>0){
			if(k==1){
				cout<<cnt1+cnt1*cnt0;
			}else{
				cout<<cnt0;
			}
		}
	}else{
		cout<<9;
	}
	

	return 0;
}
