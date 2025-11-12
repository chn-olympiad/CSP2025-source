#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	ll a[n+1],maxn=-1,sum=0,o=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=0;i<n;i++){
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
		if(sum>maxn*2) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int k=n;k>=0;k--){
		maxn=-1;sum=0;
		for(int i=0;i<n;i++){
			if(i!=k){
				maxn=max(maxn,a[i]);
				sum+=a[i];
			}
		}
		if(sum>maxn*2) o++;
		o=o%998244353;
	}
	cout<<o;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
