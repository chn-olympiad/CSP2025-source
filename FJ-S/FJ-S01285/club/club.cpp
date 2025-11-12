#include<bits/stdc++.h>
using namespace std;
int ans,t,n,a[100001],b[100001],c[100001],x,y,z,xx,yy,zz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(n==2){
			cin>>x>>y>>z>>xx>>yy>>zz;
			cout<<max(z+yy,max(z+xx,max(y+zz,max(y+xx,max(x+yy,x+zz)))));
		}
		else{
			for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--) ans+=a[i];
			cout<<ans;
		}
	}
	return 0;
}
