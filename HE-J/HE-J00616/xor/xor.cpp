#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool flag=1,flag2=1;
	int cnt0=0,cnt1=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
		if(a[i]==0){
			cnt0++;
		}
		if(a[i]==1){
			cnt1++;
		}
		if(a[i]!=1&&a[i]!=0){
			flag2=0;
		}
	}
	if(flag==1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(flag2==1&&k<=1){
		if(k==1){
			cout<<cnt1;
			return 0;
		}else if(k==0){
			cout<<(n-cnt0)/2+cnt0;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

