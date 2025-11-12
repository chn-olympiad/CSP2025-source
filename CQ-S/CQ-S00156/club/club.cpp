#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
struct cy{
	ll a,b,c,id,mx,cj;
}o[N];
bool cmp(cy x,cy y){
	return x.cj<y.cj;
}
ll cnt[5],ans=0;
void gid(int i,int id){
	if(o[i].mx==o[i].a&&id!=1) o[i].id=1;
	else if(o[i].mx==o[i].b&&id!=2) o[i].id=2;
	else o[i].id=3;
	cnt[o[i].id]++;
}
void gc(int i){
	ll mn=min({o[i].a,o[i].b,o[i].c});
	o[i].cj=o[i].mx-(o[i].a+o[i].b+o[i].c-o[i].mx-mn);
}
void solve(){
	ans=0;
	int n;
	cin>>n;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		cin>>o[i].a>>o[i].b>>o[i].c;
		o[i].mx=max({o[i].a,o[i].b,o[i].c});
		ans+=o[i].mx;
		gid(i,0);
		gc(i);
	}
	sort(o+1,o+1+n,cmp);
	ll p=1;
	while(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
		if(cnt[o[p].id]>n/2){
			o[p].mx-=o[p].cj;
			cnt[o[p].id]--;
			gid(p,o[p].id);
			ans-=o[p].cj;	
		}
		p++;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
%%%%%fzoi big old
*/
