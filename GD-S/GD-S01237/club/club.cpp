#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,ans=0,id;
ll b1,b2,b3;
const ll N=100005;
ll a[N][5];
struct note{
	ll x,val,y;
}b[N];
struct note2{
	ll x,s;
};
vector<note2> v[5];
bool cmp1(note a1,note a2){
	return a1.val>a2.val;
}
bool cmp2(note2 a1,note2 a2){
	return a1.s>a2.s;
}
void solve(){
	cin>>n;
	for(int i=1;i<=3;i++) v[i].clear();
	for(int i=1,a1,a2;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		ll ls=max(a[i][1],max(a[i][2],a[i][3]));
		if(a[i][1]==ls) {
			a1=a[i][1],a2=1;
		} else if(a[i][2]==ls) {
			a1=a[i][2],a2=2;
		} else {
			a1=a[i][3],a2=3;
		}
		b[i]={i,a1,a2};
	}
	sort(b+1,b+n+1,cmp1);
	ans=0;
	ll sum=0;
	for(int i=1,a1,a2;i<=n;i++){
		a2=b[i].y;
		a1=b[i].x;
		ans+=b[i].val;
		if(a2==1) b1=1,b2=2,b3=3;
		if(a2==2) b1=2,b2=1,b3=3;
		if(a2==3) b1=3,b2=2,b3=1;
		sum=-a[a1][b1]+max(a[a1][b2],a[a1][b3]);
		v[a2].push_back({a1,sum});
	}
	id=-1;
	if(int(v[1].size())>(n/2)) id=1;
	if(int(v[2].size())>(n/2)) id=2;
	if(int(v[3].size())>(n/2)) id=3;
	if(id!=-1){
		sort(v[id].begin(),v[id].end(),cmp2);
		for(int i=0;i<int(v[id].size())-(n/2);i++){
			ans+=v[id][i].s;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
