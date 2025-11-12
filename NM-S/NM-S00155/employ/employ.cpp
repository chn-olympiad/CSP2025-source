#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans=0;
long long a[505];
int main(){
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans/m%998%244%353;
	return 0;
}
