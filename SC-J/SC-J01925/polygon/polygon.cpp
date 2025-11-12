#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
long long n,a[5005],sum,ans,flag=1,ga=1,x=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(n==3){
		sum=a[1]+a[2]+a[3];
		if(sum*2>max(a[1],max(a[2],a[3]))){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	} 
	else if(flag){
		for(int i=3;i<=n;i++){
			for(int j=1;j<i;j++){
				ga=ga*i-ga*j;
			}
			for(int r=i;r>=1;r--){
				x*=r;
			}
			ga/=x;
			ga%=998244353;
			ans+=ga;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<"0";
	}
	return 0;
}