#include<bits/stdc++.h>
using namespace std;
int n; 
long long k;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	bool all_1=1,all_2=1,all_3=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) all_1=0;
		
		if(a[i]!=1&&a[i]!=0) all_2=0;
		
		if(a[1]!=0) all_3=0;
	}
	if(all_1){
		if(k==1){
			cout<<n;
		}
		if(k==0){
			cout<<n/2;
		}
	}
	if(!all_1&&all_3){
		if(k==0){
			cout<<n;
		}
		if(k==1){
			cout<<0;
		}
	}
	if(!all_1&&!all_3&&all_2){
		int cnt_0=0,cnt_1=0,cnt_2=0;
		for(int i=1;i<=n;i++){
			if(a[i]) cnt_1++;
			if(!a[i]) cnt_0++;
		}
		for(int i=1;i<=n;){
			if(a[i]==1&&a[i]==a[i+1]){
				cnt_2++;
				i+=2;
			}else{
				i++;
			}
		}
		if(k==0){
			cout<<cnt_0+cnt_2;
		}
		if(k==1){
			cout<<cnt_1;
		}
	}
	if(!all_1&&!all_2&&!all_3){
		
	}
	return 0;
}
