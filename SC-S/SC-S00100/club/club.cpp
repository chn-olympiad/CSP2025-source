#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5],p,p1,cnt[5],mx,d[100005],ans;
vector<int>v[5];
int nw;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
			v[i].clear();
		}
		ans=0;
		for(int i=1;i<=n;i++){
			mx=-1,p=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(mx<a[i][j]){
					mx=a[i][j];
					p=j;
				}
			}
			cnt[p]++;
			ans+=a[i][p];
			mx=-1,p1=0;
			for(int j=1;j<=3;j++){
				if(mx<a[i][j]&&j!=p){
					mx=a[i][j];
					p1=j;
				}
			}
			d[i]=a[i][p]-a[i][p1];
			v[p].push_back(d[i]);
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				sort(v[i].begin(),v[i].end());
				nw=0;
				while(cnt[i]>n/2){
					cnt[i]--;
					ans-=v[i][nw];
					nw++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 