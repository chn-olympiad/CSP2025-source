#include<bits/stdc++.h>
using namespace std;
#define int long long
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=100050;
int T,n,a[N][5],st[N][5],cnt[5],ans,go[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	qwq;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=3;i++) cnt[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			int ma=-1,p=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>ma){
					ma=a[i][j];
					p=j;
				}
			}
			st[++cnt[p]][p]=i;
			ans+=ma;
		}
		int p=0;
		for(int i=1;i<=3;i++){
			if(cnt[i]>(n/2)){
				p=i;
			}
		}
		if(p==0){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=cnt[p];i++){
			go[i]=(int)1e18;
			for(int j=1;j<=3;j++){
				if(p==j) continue;
				go[i]=min(go[i],a[st[i][p]][p]-a[st[i][p]][j]);
			}
		}
		sort(go+1,go+1+cnt[p]);
		for(int i=1;i<=cnt[p]-(n/2);i++){
			ans=ans-go[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
