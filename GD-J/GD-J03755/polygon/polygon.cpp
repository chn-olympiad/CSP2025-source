#include <bits/stdc++.h>
using namespace std;
int n,maxn,sum,a[5010]; 
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				maxn=max(a[i],a[j]);
				maxn=max(maxn,a[k]);
				if(a[i]+a[j]+a[k]>maxn*2){
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
