#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],cnt[4],ans;
vector<int> b[4];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(cnt,0,sizeof cnt);
		ans=0,b[1].clear(),b[2].clear(),b[3].clear();
		for(int i = 1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i = 1;i<=n;i++)
			if(max({a[i][1],a[i][2],a[i][3]})==a[i][1])
				cnt[1]++,ans+=a[i][1],b[1].push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
			else if(max({a[i][1],a[i][2],a[i][3]})==a[i][2])
				cnt[2]++,ans+=a[i][2],b[2].push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
			else
				cnt[3]++,ans+=a[i][3],b[3].push_back(min(a[i][3]-a[i][1],a[i][3]-a[i][2]));
		if(cnt[1]>n/2){
			sort(b[1].begin(),b[1].end());
			for(int i = 0;i<cnt[1]-n/2;i++) ans-=b[1][i];
		}
		if(cnt[2]>n/2){
			sort(b[2].begin(),b[2].end());
			for(int i = 0;i<cnt[2]-n/2;i++) ans-=b[2][i];
		}
		if(cnt[3]>n/2){
			sort(b[3].begin(),b[3].end());
			for(int i = 0;i<cnt[3]-n/2;i++) ans-=b[3][i];
		}
		cout<<ans<<'\n';
	} 
	return 0;
}
