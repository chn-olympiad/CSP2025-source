#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005],c[100005],d[100005],ca[100005],cb[100005],cc[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout );
	int t;
	cin>>t;
	while(t--){
		int x=1,y=1,z=1,ans=0;
		cin>>n;
		int zd=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]) d[i]=1,ca[x]=min(a[i]-b[i],a[i]-c[i]),x++,ans+=a[i];
			else if(b[i]>a[i]&&b[i]>c[i]) d[i]=2,cb[y]=min(b[i]-a[i],b[i]-c[i]),y++,ans+=b[i];
			else d[i]=3,cc[z]=min(c[i]-b[i],c[i]-a[i]),z++,ans+=c[i];
		}
		x--,y--,z--;
		if(x>zd){
			int m=x-zd;
			sort(ca+1,ca+x+1);
			for(int i=1;i<=m;i++){
				ans-=ca[i];
			}
		}
		if(y>zd){
			int m=y-zd;
			sort(cb+1,cb+y+1);
			for(int i=1;i<=m;i++){
				ans-=cb[i];
			}
		}
		if(z>zd){
			int m=z-zd;
			sort(cc+1,cc+z+1);
			for(int i=1;i<=m;i++){
				ans-=cc[i];
			}
		}
		//for(int i=1;i<=z;i++)
		//cout<<cc[i]<<" ";
		cout<<ans<<endl;
	}
	return 0;
}
