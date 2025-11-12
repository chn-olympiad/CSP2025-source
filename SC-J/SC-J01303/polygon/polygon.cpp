#include<iostream>
#include<cstdio>
using namespace std;
int n,ans,a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				for(int k=1;k<=n;k++){
					if(i!=k&&k!=j&&i!=j){
						if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))){
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans/2;
	return 0;
}