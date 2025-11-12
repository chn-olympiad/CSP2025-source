#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k=3;
	long long cnt,ans,maxn,a[5050];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(k<=n){
		maxn=-1;
		ans=0;
		for(int i=0;i<=n-k;i++){
			for(int j=i;j<=i+k;j++){
				ans+=a[j];
				maxn=max(maxn,a[j]);
			}
			if(ans>maxn*2){
				cnt++;
			}
		}
		k++;
	}
	cout<<cnt%998244353;
}