#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int v=max(a[i],max(a[j],a[k]));
				
				if(a[i]+a[j]+a[k]>v*2){
					ans++;
					
				}
				
			}
		}
	}
	cout<<ans;
	return 0;
}
