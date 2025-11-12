#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,a[N][5],v[N],y[N],ans,v1,v2,v3;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=v1=v2=v3=0;
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1; i<=n; i++) {
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
				v1++;
				v[i]=1;
				ans+=a[i][1];
			} else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
				v2++;
				v[i]=2;
				ans+=a[i][2];
			} else {
				v3++;
				v[i]=3;
				ans+=a[i][3];
			}
		}
		if(v1>n/2) {
			int yi=0;
			for(int i=1; i<=n; i++) {
				if(v[i]==1) {
					y[++yi]=a[i][1]-max(a[i][2],a[i][3]);
				}
			}
			sort(y+1,y+yi+1);
			yi=0;
			while(v1>n/2) {
				v1--;
				ans-=y[++yi];
			}
		} else if(v2>n/2) {
			int yi=0;
			for(int i=1; i<=n; i++) {
				if(v[i]==2) {
					y[++yi]=a[i][2]-max(a[i][1],a[i][3]);
				}
			}
			sort(y+1,y+yi+1);
			yi=0;
			while(v2>n/2) {
				v2--;
				ans-=y[++yi];
			}
		} else if(v3>n/2) {
			int yi=0;
			for(int i=1; i<=n; i++) {
				if(v[i]==3) {
					y[++yi]=a[i][3]-max(a[i][1],a[i][2]);
				}
			}
			sort(y+1,y+yi+1);
			yi=0;
			while(v3>n/2) {
				v3--;
				ans-=y[++yi];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
