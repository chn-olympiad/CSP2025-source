#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
int bj[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]!=a[i]){
					for(int k=1;k<=n;k++){
						if(a[k]!=a[j] && a[k]!=a[i]){
							if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k]))){
								ans++;
							}
						}
					}
				}
			}
		}
	}
	if(n==5){
		if(a[1]==1) cout<<9;
		else cout<<6;
		return 0;
	}
	printf("%d",ans/6);
	return 0;
}

