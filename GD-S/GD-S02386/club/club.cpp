#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+7;
ll T;
ll n,a[N][5];
ll num[N],buk[N],tot[5],maxn;
ll a2n,a3n;
ll a1[N],a2[N],a3[N];
void DfS(int x){
	if(x>n){
		ll sum=0;
		for(ll i=1;i<=n;i++){
			sum+=a[i][num[i]];
//			cout<<num[i]<<' ';
		}
//		cout<<endl;
		maxn=max(maxn,sum);
		return ;
	}
	if(tot[1]<n/2){
		num[x]=1;
		tot[1]++;
		DfS(x+1);
		tot[1]--;
	}
	if(tot[2]<n/2){
		num[x]=2;
		tot[2]++;
		DfS(x+1);
		tot[2]--;
	}
	if(tot[3]<n/2){
		num[x]=3;
		tot[3]++;
		DfS(x+1);
		tot[3]--;
	}
}
void solve1(){
	for(ll i=1;i<=n;i++){
		a1[i]=a[i][1];
	}
	sort(a1+1,a1+n+1);
	for(ll i=n;i>n/2;i--){
		maxn+=a1[i];
	}
	printf("%lld\n",maxn);
}
void solve2(){
	for(ll i=1;i<=n;i++){
		a2[i]=a[i][2];
		a1[i]=a[i][1];
	}
	sort(a2+1,a2+n+1);
	sort(a1+1,a1+n+1);
	ll l1=1,l2=1,nb1=0,nb2=0;
	while(nb1+nb2<n){
		if(a1[l1]>a2[l2]&&nb1<n/2){
			maxn+=a1[l1];
			l1++;
			nb1++;
		}
		else{
			maxn+=a2[l2];
			l2++;
			nb2++;
		}
	}
	printf("%lld\n",maxn);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		maxn=0;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i][1]);
			scanf("%lld",&a[i][2]);
			scanf("%lld",&a[i][3]);
			a2n+=a[i][2],a3n+=a[i][3];
		}
		if(a2n==0&&a3n==0){
			solve1();
			continue;
		}
		if(a3n==0){
			solve2();
			continue;
		}
		DfS(1);
		cout<<maxn<<endl;
	}
	return 0;
}

