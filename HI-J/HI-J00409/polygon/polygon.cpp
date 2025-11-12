#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int ans=0,maxn=0;
			for(int l=i;l<=j;l++){
				maxn=max(maxn,a[l]);
				ans+=a[l];
			}
			if(ans>2*maxn){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
