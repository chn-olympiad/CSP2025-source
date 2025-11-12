#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		int cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt1++;
		}
		cout<<cnt1;
	}else if(k==0){
		int sum=0;
		int cnt0=0,sum1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt0++;
			if(a[i]==1) sum1++;
			if(a[i]==0){
				sum+=sum1/2;
				sum1=0;
			}
		}
		cout<<sum+cnt0;
	}
	return 0;
}

