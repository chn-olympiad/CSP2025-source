#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+7;
const int mod=998244353;
int n,m;
int s[N],c[N],buk[N];
int num[N],sum,sus,ans;
void DfS(int x){
	if(x>n){
		sum=0,sus=0;
		for(int i=1;i<=n;i++){
			if(sum<c[num[i]]){
				if(s[i]==1){
					sus++;
				}
				else sum++;
			}
			else sum++;
		}
		if(sus>=m){
			ans++;
//			for(int i=1;i<=n;i++){
//				cout<<num[i]<<' ';
//			}
//			cout<<endl;
		}
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(buk[i]==0){
			buk[i]=1;
			num[x]=i;
			DfS(x+1);
			buk[i]=0;
		}
	}
}
void solve1(){
	ll lans;
	lans=1;
	for(ll i=1;i<=n;i++){
		lans*=i;
		lans%=998244343;
	}
	printf("%lld\n",lans);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	int nb1=0;
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		nb1+=s[i];
	}
	if(nb1==n){
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	DfS(1);
	printf("%d\n",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
