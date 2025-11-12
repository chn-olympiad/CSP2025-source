#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][5],cnt[5];
vector<int> v[5],num;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		num.clear();
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=3;i++)
			v[i].clear();
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int now=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>a[i][now]) now=j;
			}
			cnt[now]++,v[now].push_back(i),ans+=a[i][now];
		}
		for(int i=1;i<=3;i++)
			if(cnt[i]>n/2){
				for(auto &j:v[i]){
					int mx=0;
					for(int k=1;k<=3;k++)
						if(k!=i) mx=max(mx,a[j][k]);
					num.push_back(a[j][i]-mx);
				}
				sort(num.begin(),num.end());
				for(int j=0;j<cnt[i]-n/2;j++)
					ans-=num[j];
				break;
			}
		cout<<ans<<"\n";
	}
	return 0;
}
