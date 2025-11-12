#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<n-3;i++){
		for(int j=n+1;j<n-2;j++){
			for(int k=j+1;k<n;k++){
				int maxn=max(a[i],a[j]);
				maxn=max(maxn,a[k]);
				if(a[i]+a[j]+a[k]>2*maxn){
					ans++;
				}
			}
		}
	}
	ans=ans%3;
	cout<<ans;
	return 0;
}
