#include<bits/stdc++.h>
#define modd 998244353
using namespace std;
int n,Aa[6000],mx=0;
long long ans=0,cnt,cnt2,bf;
int qp(int base,int power){
	int t=1;
	while(power){
		if(power&1){
			t=t*base;
		}
		base=base*base;
		power>>=1;
	}
	return t;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>Aa[i];
		mx=max(mx,Aa[i]);
	}
//	cout<<mx<<endl;
	if(n<=3){
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=Aa[i];
		if(sum-mx>mx)cout<<1;
		else cout<<0;
		return 0;
	}
	if(mx==1){
		for(int i=3;i<=n-1;i++){
			cnt=1,cnt2=1;
			for(int j=n-1,k=i;j>=n-i+1;j--,k--){
				cnt=cnt*j;
				cnt2=cnt2*k;
			}
			ans+=cnt/cnt2;
		}
		cout<<ans%modd;
		return 0;
	}
	
}