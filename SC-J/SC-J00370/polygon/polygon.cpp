#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int a[5005]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=0,maxx=0;
	 	for(int j=i;j<=n;j++){
	 		sum+=a[j];
	 		maxx=max(maxx,a[j]);
		}
		if(!(2*maxx>=sum))ans=(ans+1)%998244353;
	}
	cout<<ans;
	return 0;
}