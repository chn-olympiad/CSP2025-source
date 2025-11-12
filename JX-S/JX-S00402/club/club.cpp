#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
const int N=1e5+10;
int t,n,ans,cnt[4],a[N][4],b[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>t;
	while(t--){
		cin>>n;
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		int cntb=0;
		for(int i=1;i<=n;++i) b[i]=1e9;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
			}
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				++cnt[1];
				ans+=a[i][1];
			}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				++cnt[2];
				ans+=a[i][2];
			}else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
				++cnt[3];
				ans+=a[i][3];
			}
		}
		if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
			cout<<ans<<'\n';
			continue;
		}else{
			int tag=0;
			for(int i=1;i<=3;++i){
				if(cnt[i]>n/2) tag=i;
			}
			
			for(int i=1;i<=n;++i){
				if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3] && tag==1){
					b[++cntb]=i;
				}else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3] && tag==2){
					b[++cntb]=i;
				}else if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2] && tag==3){
					b[++cntb]=i;
				}
			}
			
			for(int i=1;i<=cntb;++i){
				int k=b[i];
				b[i]=1e9;
				for(int j=1;j<=3;++j){
					if(j==tag) continue;
					b[i]=min(a[k][tag]-a[k][j],b[i]);
				}
			}
			sort(b+1,b+cntb+1);
			for(int i=1;i<=cnt[tag]-n/2;++i){
				ans-=b[i];
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1
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
