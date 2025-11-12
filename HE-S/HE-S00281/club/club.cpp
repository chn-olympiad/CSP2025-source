#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+10;
struct ycl{
	long long bj,maxx,cz;
}yclm[N];
struct bf{
	long long fr,se,th,yx;
}bfm[N];
bool cmp(ycl a,ycl b){
	return a.cz>=b.cz;
}
ll n,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int l=1;l<=t;l++){
		cin>>n;
		ll kkk=n/2,kkf=0,kks=0,kkt=0,cnt=0,fcnt=0,scnt=0,tcnt=0;
		for(int i=1;i<=n;i++){
			ll maxn=-1e5;
			scanf("%d%d%d",& bfm[i].fr,&bfm[i].se,&bfm[i].th);
			maxn = max(bfm[i].fr,bfm[i].se);
			maxn = max(maxn,bfm[i].th);
			yclm[i].bj = i; yclm[i].maxx = maxn;
			if(maxn == bfm[i].fr){
				bfm[i].yx = 1; yclm[i].cz = maxn-max(bfm[i].se,bfm[i].th);
			}
			else if(maxn == bfm[i].se){
				bfm[i].yx = 2; yclm[i].cz = maxn-max(bfm[i].fr,bfm[i].th);
			}
			else{
				bfm[i].yx = 3; yclm[i].cz = maxn-max(bfm[i].se,bfm[i].fr);
			}
		}
		sort(yclm+1,yclm+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(fcnt == kkk) kkf=1;
			if(scnt == kkk) kks=1;
			if(tcnt == kkk) kkt=1;
			if(bfm[yclm[i].bj].yx == 1){
				if(!kkf){
					fcnt++;  cnt += yclm[i].maxx;
				}else{
					cnt += max(bfm[yclm[i].bj].se,bfm[yclm[i].bj].th);
				}
			}else if(bfm[yclm[i].bj].yx == 2){
				if(!kks){
					scnt++;  cnt += yclm[i].maxx;
				}else{
					cnt += max(bfm[yclm[i].bj].fr,bfm[yclm[i].bj].th);
				}
			}else if(bfm[yclm[i].bj].yx == 3){
				if(!kkt){
					tcnt++;  cnt += yclm[i].maxx;
				}else{
					cnt += max(bfm[yclm[i].bj].fr,bfm[yclm[i].bj].se);
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
