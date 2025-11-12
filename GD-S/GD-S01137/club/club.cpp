#include<bits/stdc++.h>
using namespace std;
bool stt;
const int N=1e5+10;
int n,m;
int cnt[3];
struct node{
	int val,val2;
}l[3][N];
bool cmp(node x,node y){
	return x.val-x.val2>y.val-y.val2;
}
void solve(){
	cin>>n;
	int ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x>=y&&x>=z){
			ans+=x,l[0][++cnt[0]]={x,max(y,z)};
		}else if(y>=x&&y>=z){
			ans+=y,l[1][++cnt[1]]={y,max(x,z)};
		}else{
			ans+=z,l[2][++cnt[2]]={z,max(x,y)};
		}
	}
	int lim=n/2;
	if(cnt[0]<=lim&&cnt[1]<=lim&&cnt[2]<=lim) return cout<<ans<<"\n",void();
	int res=0;
	if(cnt[1]>lim) res=1;
	if(cnt[2]>lim) res=2;
	sort(l[res]+1,l[res]+1+cnt[res],cmp);
	while(cnt[res]>lim){
		ans-=l[res][cnt[res]].val-l[res][cnt[res]].val2;
		cnt[res]--;
	}
	cout<<ans<<"\n";
}
bool edd;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--) solve();
	cerr<<(&edd-&stt)/1024.0/1024<<"\n";
	return 0;
}
