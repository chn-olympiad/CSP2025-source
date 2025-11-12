#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=1;j<=n-2;j++){
		for(int k=j+1;k<=n-1;k++){
			for(int q=k+1;q<=n;q++){
				if(a[k]+a[j]>a[q]) ans++;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
