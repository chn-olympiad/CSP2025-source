#include<bits/stdc++.h>
using namespace std;
long long n,a[5007],num,ans,sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=1<<n;i++){
		num=0;
		sum=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				num+=a[j];
				sum=max(sum,a[j]);
			}
		}
		if(sum*2<num){
			ans++;
			ans%=998224353;
		}
	}
	cout<<ans;
	return 0;
} 
