#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int a[N];
int n;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//可选不连续！ dp?  
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){//结尾 
		for(int j=1;j<=i-2;j++){//起点 
		long long sum=0;
		int maxn=0;	
			for(int k=j;k<=i;k++){//加 
//				cout<<i<<" "<<j<<" "<<k<<"\n";
				sum+=a[i];
				maxn=max(a[i],maxn);
			}
			if(maxn*2<sum){
				ans++;
				ans%=mod; 
			}
		}
	}
	cout<<ans;
	return 0;
}