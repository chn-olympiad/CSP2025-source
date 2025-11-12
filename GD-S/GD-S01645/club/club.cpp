#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+100;
int T,a[N][4],d1[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		int n,ans=0,cnt1=0,cnt2=0,cnt3=0,cnt=0,u=0,v1=0,v2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			d1[i]=0;
		}
		for(int i=1;i<=n;i++){
			int mx=max({a[i][1],a[i][2],a[i][3]});
			if(mx==a[i][1]){
				cnt1++;
			}
			else if(mx==a[i][2]){
				cnt2++;
			}else if(mx==a[i][3]){
				cnt3++;
			}
			ans+=mx;
		}
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<ans<<'\n'; 
		if(cnt1>n/2){
			u=1,v1=2,v2=3;
		}else if(cnt2>n/2){
			u=2,v1=1,v2=3;
		}else if(cnt3>n/2){
			u=3,v1=1,v2=2;
		}else {
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int mx=max({a[i][1],a[i][2],a[i][3]});
			if(mx==a[i][u]){
				d1[++cnt]=min(a[i][u]-a[i][v1],a[i][u]-a[i][v2]);
			}
		}
		sort(d1+1,d1+1+cnt);
		for(int i=1;i<=max({cnt1,cnt2,cnt3})-n/2;i++){
			ans-=d1[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
