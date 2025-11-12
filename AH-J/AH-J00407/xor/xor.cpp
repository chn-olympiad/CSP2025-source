#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int sum[500005];
int s(int l,int r){
	return sum[r]^sum[l-1];
}
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i]>1) return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	if(check1()){
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if(s(l,r)==k){
					ans++;
					l=r;
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			for(int l=j;l<=n;l++){
				if(s(j,l)==k){
					j=l;
					sum++;
					break;
				}
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
