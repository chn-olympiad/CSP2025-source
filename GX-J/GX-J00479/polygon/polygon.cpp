#include <bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		int ans=0,c;
		int maxx=-1;
		for(int j=n-i;j<=n;j++){
			for(int x=1;x<=j;x++){
				ans+=a[x];
				maxx=max(maxx,a[x]);
				c++;
				}
				if(ans>maxx*2 && c>=3){
				cnt++;
			}
		}
	}
		cout<<cnt%998244353;
	return 0;
}
