#include<bits/stdc++.h>
using namespace std;
int a[2020][2020];
int maxx1[10000010],maxx3[10000010],maxx2[10000010],x,y,z;
int b[3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		int n,ans=0;
		cin>>n;
		int cnt=n/2;
		for(int i=1; i<=3; i++) b[i]=0;
		for(int i=1; i<=n; i++) maxx1[i]=-1,maxx2[i]=-1,maxx3[i]=-1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) cin>>a[i][j];
			for(int j=1; j<=3; j++) {
				if(a[i][j]>maxx1[i]) {
					maxx1[i]=a[i][j];
					x=j;
				}
			}
			for(int j=1; j<=3; j++) {
				if(a[i][j]>maxx2[i]&&j!=x) {
					maxx2[i]=a[i][j];
					y=j;
				}
			}
			for(int j=1; j<=3; j++) {
				if(a[i][j]>maxx3[i]&&j!=x&&j!=y) {
					maxx3[i]=a[i][j];
					z=j;
				}
			}
			if(b[x]+1<=cnt) {
				b[x]++;
				ans+=maxx1[i];
			} else if(b[y]+1<=cnt) {
				b[y]++;
				ans+=maxx2[i];
			} else {
				b[z]++;
				ans+=maxx3[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
