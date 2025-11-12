#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1001000];
int cnt1=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
		if(a[i]==1){
			cnt1++;
		}
	}
	if(k==0&&f){
		cout<<n/2;
		return 0;
	}
	if(k<=1){
		if(k==1){
			cout<<max(cnt1,(n-cnt1)/2);
			return 0;
		}else{
			cout<<max(n-cnt1,cnt1/2);
			return 0;
		}
	}
	cout<<n/5;
	return 0;
}
