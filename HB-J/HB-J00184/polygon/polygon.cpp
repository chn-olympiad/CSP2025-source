#include<bits/stdc++.h>
using namespace std;
int a[5001],n,ans=0,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;i++){
			for(int k=j;k<=n;i++){
				m=max(max(a[i],a[j]),a[k]);
				if(a[i]+a[j]+a[k]>2*m)ans+=1;
				}
			}
		}
	cout<<ans;
}
