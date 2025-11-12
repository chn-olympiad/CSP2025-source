#include <bits/stdc++.h>
using namespace std;
int a[600005],js[600005]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,k,ans=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			for(int z=3;z<=n;z++){
				if(a[i]+a[j]+a[z]>a[z]*2&&i!=j&&j!=z&&i!=z){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
