#include<bits/stdc++.h>
using namespace std;
long long n,k,sum,ans,a[10005],b[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			for(int k=i;k<=j;k++){
				sum=max(sum,a[k]);
			}
			if(b[j]-b[i]>sum){
				ans++;
			}
		}
	}
	cout<<ans%998244353;
return 0;
}
