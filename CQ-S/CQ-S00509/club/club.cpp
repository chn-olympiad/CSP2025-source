#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005][3],siz[3],b[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,ans=0;cin>>n;siz[0]=siz[1]=siz[2]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int ma=max(a[i][0],max(a[i][1],a[i][2]));
			if(ma==a[i][0]) siz[0]++;
			else if(ma==a[i][1]) siz[1]++;
			else if(ma==a[i][2]) siz[2]++;
			ans+=ma;
		}
		int ma=max(siz[0],max(siz[1],siz[2]));
		if(ma<=n/2) cout<<ans<<'\n';
		else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				int ma=max(a[i][0],max(a[i][1],a[i][2]));
				int id=0,maa;
				if(ma==a[i][0]) id=0,maa=max(a[i][1],a[i][2]);
				else if(ma==a[i][1]) id=1,maa=max(a[i][0],a[i][2]);
				else if(ma==a[i][2]) id=2,maa=max(a[i][1],a[i][0]);
				if(siz[id]>n/2){
					cnt++;b[cnt]=ma-maa;
				}
			}
			sort(b+1,b+1+cnt);
			for(int i=1;i<=cnt-n/2;i++) ans-=b[i];
			cout<<ans<<'\n';
		}
	}
	return 0;
}
