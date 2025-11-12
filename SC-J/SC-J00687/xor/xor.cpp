#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,mind=1;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mind=min(mind,a[i]);
	}
	
	
	if(k==0&&mind==1){
		cout<<n/2;
	}
	
	else{
		if(k==0){
			int cnt0=0,cnt1=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) cnt0++;
				if(a[i]==1) cnt1++;
				if(cnt0==1||cnt1==2){
					cnt++;
					cnt0=0;
					cnt1=0;
				}
			}
			cout<<cnt;
		}
		else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt++;
			}
			cout<<cnt;
		}
	}
}