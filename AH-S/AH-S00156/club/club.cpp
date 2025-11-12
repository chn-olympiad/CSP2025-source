#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
using pii=pair<int,int>;
int n,now[4],ans;
struct node{
	pii s[4];bool vis;
	bool operator < (const node &x) const {
		return s[1].first-s[2].first>x.s[1].first-x.s[2].first;
	}
}a[N];
bool cmp(pii a,pii b){
	if(a.first*now[a.second]==b.first*now[b.second]) return now[a.second]>now[b.second];
	else return a.first*now[a.second]>b.first*now[b.second];
}
int co[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;cin>>T;
	while(T--){
		cin>>n;now[1]=now[2]=now[3]=3;
		co[1]=co[2]=co[3]=ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){cin>>a[i].s[j].first;a[i].s[j].second=j;}
			sort(a[i].s+1,a[i].s+4,cmp);a[i].vis=0;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			co[a[i].s[1].second]++;
			ans+=a[i].s[1].first;
			a[i].vis=1;
			if(co[a[i].s[1].second]==n/2){
				now[a[i].s[1].second]=0;
				break;
			}
		}
		for(int i=1;i<=n;i++) sort(a[i].s+1,a[i].s+4,cmp);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i].vis) continue;
			co[a[i].s[1].second]++;
			ans+=a[i].s[1].first;
			a[i].vis=1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
