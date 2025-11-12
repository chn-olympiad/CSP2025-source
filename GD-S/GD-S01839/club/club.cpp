#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int t,n,a[N][3],mx[N],mx2[N];
vector<int> g[3];
int val(int x){return a[x][mx[x]]-a[x][mx2[x]];}
bool cmp(int x,int y){return val(x)<val(y);}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			mx[i]=mx2[i]=-1;
			for(int j=0;j<3;j++)cin>>a[i][j];
			for(int j=0;j<3;j++){
				if(!~mx[i]||a[i][mx[i]]<a[i][j])mx2[i]=mx[i],mx[i]=j;
				else if(!~mx2[i]||a[i][mx2[i]]<a[i][j])mx2[i]=j;
			}
			ans+=a[i][mx[i]],g[mx[i]].push_back(i);
//			cout<<mx[i]<<' '<<mx2[i]<<'\n';
		}
//		cout<<ans<<'\n';
		for(int i=0;i<3;i++)if((int)g[i].size()>n/2){
			sort(g[i].begin(),g[i].end(),cmp);
			for(int j=0;j<(int)g[i].size()-n/2;j++)ans-=val(g[i][j]);
		}
		cout<<ans<<'\n';
		for(int i=0;i<3;i++)g[i].clear();
	}
}
