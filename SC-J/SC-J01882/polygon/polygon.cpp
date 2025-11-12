#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n>25){
		
		for(int i=3;i<=n;i++){
			long long sum=1;
			for(int j=n;j>=n-i+1;j--){
				sum=(sum*j)%mod;
			}for(int j=1;j<=i;j++){
				sum=sum/j;
			}ans=(ans+sum)%mod;
		}cout<<ans;
		return 0;
	}
	for(int i=1;i<pow(2,n);i++){
		int maxn=0,sum=0;
		int p=i,j=1;
		while(p){
			if(p%2==1){
				sum+=a[j];
				maxn=max(maxn,a[j]);
			}j++;
			p/=2;
		}if(sum>maxn*2){
			ans++;
		}
	}cout<<ans;
	return 0;
}