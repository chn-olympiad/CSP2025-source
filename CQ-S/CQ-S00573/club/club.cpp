#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int a[maxn][4],mx[maxn],se[maxn],del[maxn];
vector<int>vec[4];
bool cmp(int x,int y){
	return del[x]>del[y];
}
void solve(){
	int n,ans=0;cin>>n;
	for(int j=1;j<=3;j++)vec[j].clear();
	for(int i=1;i<=n;i++){
		mx[i]=se[i]=0;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(!mx[i]||a[i][mx[i]]<a[i][j])se[i]=mx[i],mx[i]=j;
			else if(!se[i]||a[i][se[i]]<a[i][j])se[i]=j;
		}
		vec[mx[i]].push_back(i);
		ans+=a[i][mx[i]];
		del[i]=a[i][mx[i]]-a[i][se[i]];
	}
	for(int j=1;j<=3;j++){
		sort(vec[j].begin(),vec[j].end(),cmp);
		while(vec[j].size()>n/2){
			ans-=a[vec[j].back()][mx[vec[j].back()]];
			ans+=a[vec[j].back()][se[vec[j].back()]];
			vec[j].pop_back();
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
//$O(n\log n)$, simple.
