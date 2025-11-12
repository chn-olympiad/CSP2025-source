#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005],aa,bb,cc,r[200005],ans[10],d,dd,ma;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,o;
	cin>>t;
	o=t;
	for(;t>=1;t--){
		cin>>n;
		aa=0;
		bb=0;
		cc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				r[i]=1;
				aa++;
				ans[t]+=a[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				r[i]=2;
				bb++;
				ans[t]+=b[i];
			}
			else if(c[i]>=b[i]&&c[i]>=a[i]){
				r[i]=3;
				cc++;
				ans[t]+=c[i];
			}
		}
		if(aa>n/2){
			for(;aa>n/2;aa--){
				ma=20000;
				for(int i=1;i<=n;i++){
					if(r[i]==1){
						if(a[i]-b[i]<ma){
							ma=a[i]-b[i];
							d=i;
							dd=2;
						}
						if(a[i]-c[i]<ma){
							ma=a[i]-c[i];
							d=i;
							dd=3;
						}
					}
				}
				r[d]=dd;
				ans[t]-=ma;
			}
		}
		else if(bb>n/2){
			for(;bb>n/2;bb--){
				ma=20000;
				for(int i=1;i<=n;i++){
					if(r[i]==2){
						if(b[i]-a[i]<ma){
							ma=b[i]-a[i];
							d=i;
							dd=1;
						}
						if(b[i]-c[i]<ma){
							ma=b[i]-c[i];
							d=i;
							dd=3;
						}
					}
				}
				r[d]=dd;
				ans[t]-=ma;
			}
		}
		else if(cc>n/2){
			for(;cc>n/2;cc--){
				ma=20000;
				for(int i=1;i<=n;i++){
					if(r[i]==1){
						if(c[i]-b[i]<ma){
							ma=c[i]-b[i];
							d=i;
							dd=2;
						}
						if(c[i]-a[i]<ma){
							ma=c[i]-a[i];
							d=i;
							dd=1;
						}
					}
				}
				r[d]=dd;
				ans[t]-=ma;
			}
		}
	}
	for(int i=o;i>=1;i--){
		cout<<ans[i]<<endl;
	}
	return 0;
}
