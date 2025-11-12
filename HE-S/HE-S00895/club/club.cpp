#include"bits/stdc++.h"
using namespace std;
#define int long long
const int maxn = 1e5+10;
int T,n,a[maxn][3],b[3],c[maxn];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int Mx=max({a[i][0],a[i][1],a[i][2]});
			if(Mx==a[i][0]){
				b[0]++;
			}else if(Mx==a[i][1]){
				b[1]++;
			}else{
				assert(Mx==a[i][2]);
				b[2]++;
			}
		}
		if(max({b[0],b[1],b[2]})<=n/2){
			int Su=0;
			for(int i=1;i<=n;i++)
				Su+=max({a[i][0],a[i][1],a[i][2]});
			cout<<Su<<'\n';
		}else{
			int Ix=-1;
			if(b[0]>n/2)Ix=0;
			if(b[1]>n/2)Ix=1;
			if(b[2]>n/2)Ix=2;
			assert(Ix!=-1);
			for(int i=1;i<=n;i++)
				swap(a[i][0],a[i][Ix]);
			int Su=0;
			for(int i=1;i<=n;i++){
				c[i]=max(a[i][1],a[i][2])-a[i][0];
				Su+=a[i][0];
			}
			sort(c+1,c+n+1,greater<int>());
			for(int i=1;i<=n/2;i++)
				Su+=c[i];
			cout<<Su<<'\n';
		}
		b[0]=b[1]=b[2]=0;
	}
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<'\n';
}
