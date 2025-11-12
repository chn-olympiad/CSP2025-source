#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5000+10],b[5000+10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=n;i>=1;i--)
		if(a[i]<b[i])
			for(int j=0;j<i-1;j++)
				if(b[i]-b[j]>a[i]*2){
					ans++;
				}
				else break;		
	cout<<ans%998244353;
	return 0;
} 
