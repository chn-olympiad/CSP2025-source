#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],cmp1[100005],cmp2[100005];
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool zt1=0,zt2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0) zt1=1;
			if(c[i]!=0) zt2=1;
			cmp1[i]=(a[i]-b[i]),cmp2[i]=(b[i]-c[i]);
		}if(zt1==0&&zt2==0){
			sort(a+1,a+1+n);
			int ans=0;
			for(int i=n;i>n/2;i--) ans+=a[i];
			cout<<ans<<'\n';
		}else if(n==2&&zt1&&zt2){
			int ans=max(a[1]+b[2],max(a[1]+c[2],max(b[1]+a[2],max(b[1]+c[2],max(c[1]+a[2],c[1]+b[2])))));
			cout<<ans;
		}
	}
	return 0;
}
