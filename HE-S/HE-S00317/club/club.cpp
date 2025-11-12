#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
struct nd1{
	ll id,v;
};
struct nd{
	nd1 val[4];
};
bool fk=1;
ll t,n,num[4],ans[N];
nd c[N];
ll f[N][4];
ll cnt[N][4][4];
bool cmp(nd a,nd b){
	if(a.val[1].v!=b.val[1].v)return a.val[1].v>b.val[1].v;
	else {
		if(a.val[2].v!=b.val[2].v)return a.val[2].v>b.val[2].v;
		else {
			return a.val[3].v>b.val[3].v;
		}
	}
}
bool cmp1(nd1 a,nd1 b){
	return a.v>b.v;
}
void slove(){
	if(fk){
		ll ans=0;
		for(ll i=1;i<=n/2;i++){
			ans+=c[i].val[1].v;
		}
		return ;
	}
	ll ans=0;
	for(ll i=1;i<=3;i++){
		for(ll j=1;j<=3;j++){
			ll pi=c[i].val[j].id,vi=c[i].val[j].v;
			f[1][i]=vi;
			cnt[1][i][pi]=1;
		}
	}
	for(ll i=2;i<=n;i++){
		for(ll j=1;j<=3;j++){
			ll pi=c[i].val[j].id,vi=c[i].val[j].v;
			if(cnt[i-1][j][pi]>=n/2){
				cnt[i][j][pi]=N;
				continue;
			}
			f[i][j]=max(f[i][j],f[i-1][j]+vi);
			cnt[i][j][pi]++;
		}
	}
	for(ll i=1;i<=3;i++){
		ans=max(ans,f[n][i]);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=3;j++){
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	printf("%lld\n",ans);
	return;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		memset(num,0,sizeof(num));
		memset(f,0,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			cin >> c[i].val[1].v >> c[i].val[2].v >> c[i].val[3].v;
			if(c[i].val[2].v||c[i].val[3].v)fk=0;
			sort(c[i].val+1,c[i].val+1+3,cmp1);
 		}
		sort(c+1,c+1+n,cmp);
 		slove();
	}
	return 0;
}
