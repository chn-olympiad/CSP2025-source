#include<bits/stdc++.h>
#define N 100010
#define int long long
using namespace std;
int n,a[N],b[N],c[N],vis[N],f[N];

bool cmp1(int x,int y){
	return x>y;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		int sia,sib,sic,ans=0;
		sia=sib=sic=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			int mx=max({a[i],b[i],c[i]});
			if(mx==a[i]){
				sia++;
				vis[i]=1;
			}else if(mx==b[i]){
				sib++;
				vis[i]=2; 
			}else if(mx==c[i]){
				sic++;
				vis[i]=3;
			}
			ans+=mx;
		}
		int md=(n>>1);
		if(sia>md){
			int len=sia-md,cnt=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					cnt++;
					f[cnt]=max(b[i]-a[i],c[i]-a[i]);
				}
			}
			sort(f+1,f+cnt+1,cmp1);
			for(int i=1;i<=len;i++){
				ans+=f[i];
			}
		}else if(sib>md){
			int len=sib-md,cnt=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==2){
					cnt++;
					f[cnt]=max(a[i]-b[i],c[i]-b[i]);
				}
			}
			sort(f+1,f+cnt+1,cmp1);
			for(int i=1;i<=len;i++){
				ans+=f[i];
			}
		}else if(sic>md){
			int len=sic-md,cnt=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==3){
					cnt++;
					f[cnt]=max(a[i]-c[i],b[i]-c[i]);
				}
			}
			sort(f+1,f+cnt+1,cmp1);
			for(int i=1;i<=len;i++){
				ans+=f[i];
			}
		}
		cout<<ans<<'\n';
//		int s=0;
//		for(int i=1;i<=n;i++){
//			cin>>a[i]>>b[i]>>c[i];
//			s+=a[i];
//			d[i]=nd{b[i]-a[i],i};
//		}
//		sort(d+1,d+n+1,cmp);
//		int md=n>>1;
//		for(int i=1;i<=md;i++){
//			s+=d[i].va;
//			vis[d[i].di]=1;
//		}
//		for(int i=1;i<=n;i++){
//			if(vis[i]){
//				f[i]=c[i]-b[i];
//			}else{
//				f[i]=c[i]-a[i];
//			}
//		}
//		sort(f+1,f+n+1,cmp1);
//		int ans=s;
//		for(int i=1;i<=md;i++){
//			s+=f[i];
//			ans=max(ans,s); 
//		}
//		cout<<ans<<endl;
	}
	return 0;
} 
/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
