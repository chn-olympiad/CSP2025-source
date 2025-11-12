#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
		int n;
		ll ans=0,ss;
		cin>>n;
		int m=n/2;
		int a[100005],b[100005],c[100005],d[300005],g[5],gg[5];
		for(int j=1; j<=n; j++) {
			cin>>a[j]>>b[i]>>c[i];
			g[1]=a[j];
			g[2]=b[j];
			g[3]=c[j];
			int mx=max(g[1],g[2]);
			mx=max(mx,g[3]);
			if(mx==g[1]) {
				gg[1]++;			
			} else if(mx==g[2]) {
				gg[2]++;
			} else {
				gg[3]++;
			}			
			if(gg[1]>m) {
				gg[1]--;
				if(g[2]>g[3]){
					gg[2]++;
				}else{
					gg[3]++;
				}
			}
			if(gg[2]>m) {
				gg[2]--;
				if(g[1]>g[3]){
					gg[1]++;
				}else{
					gg[3]++;
				}
			}
			if(gg[3]>m) {
				gg[3]--;
				if(g[2]>g[1]){
					gg[2]++;
				}else{
					gg[1]++;
				}
			}
			sort(g+1,g+1+3);
			d[3*i-2]=g[3]-g[2];
			d[3*i-1]=g[2]-g[1];
			d[3*i]=g[3]-g[1];
			sort(a+1,a+1+n);
			sort(b+1,b+1+n);
			sort(c+1,c+1+n);
			for(int k=gg[1];1<=k;k--){
				ans+=a[k];
			}
			for(int k=gg[2];1<=k;k--){
				ans+=b[k];
			}
			for(int k=gg[3];1<=k;k--){
				ans+=c[k];
			}
		}
		cout<<ans;
	}
	return 0;
}