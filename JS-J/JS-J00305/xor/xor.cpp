#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0;
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt1++;
		}
		if(a[i]==0){
			cnt0++;
		}
		if(a[i]==k){
			vis[i]=1;
			ans++;
		}
	}
	if(cnt1==n&&k==0){
		cout<<n/2;
	}else if(cnt1+cnt0==n&&k==0){
		cout<<cnt0+cnt1/2;
	}else if(cnt1+cnt0==n&&k==1){
		cout<<cnt1+cnt0/2;
	}else{
		cout<<ans;
	} 
    fclose(stdin);
    fclose(stdout);
	return 0;
}
