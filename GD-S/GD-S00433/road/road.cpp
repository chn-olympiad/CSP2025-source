#include<bits/stdc++.h>
using namespace std;
#define int long long
const int THE_FIREFLY_COOK=1e5+5;
struct _{
	int iniit[4],mx,vx,vy,im,ix,iy;
	
}AR26710[THE_FIREFLY_COOK];
int n;
int fireflyIV[4],k;
bool firefly_fly_on_fire__live_to_die[THE_FIREFLY_COOK];
int live_to_fight,fight_for_life;
int I_LOVE_FIREFLY_FOREVER=0;
bool cmp(_ A,_ B){
	return A.mx-A.vx<B.mx-B.vx;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T;cin>>T;
	while(T--){
		cin>>n;I_LOVE_FIREFLY_FOREVER=0;
		memset(fireflyIV,0,sizeof fireflyIV);
		memset(firefly_fly_on_fire__live_to_die,0,sizeof firefly_fly_on_fire__live_to_die);//important
		for(int finu_la=1;finu_la<=n;finu_la++){
			scanf("%lld%lld%lld",&AR26710[finu_la].iniit[1],&AR26710[finu_la].iniit[2],&AR26710[finu_la].iniit[3]);
			
			AR26710[finu_la].mx=AR26710[finu_la].iniit[1];
			AR26710[finu_la].vx=AR26710[finu_la].iniit[2];
			AR26710[finu_la].vy=AR26710[finu_la].iniit[3];
			AR26710[finu_la].im=1;
			AR26710[finu_la].ix=2;
			AR26710[finu_la].iy=3;
			if(AR26710[finu_la].mx<AR26710[finu_la].vx){
				swap(AR26710[finu_la].mx,AR26710[finu_la].vx);
				swap(AR26710[finu_la].im,AR26710[finu_la].ix);
			}
			if(AR26710[finu_la].mx<AR26710[finu_la].vy){
				swap(AR26710[finu_la].mx,AR26710[finu_la].vy);
				swap(AR26710[finu_la].im,AR26710[finu_la].iy);
			}
			if(AR26710[finu_la].vx<AR26710[finu_la].vy){
				swap(AR26710[finu_la].vx,AR26710[finu_la].vy);
				swap(AR26710[finu_la].ix,AR26710[finu_la].iy);
			}
//			AR26710[finu_la].vy=AR26710[finu_la].vx-AR26710[finu_la].vy;
//			AR26710[finu_la].vx=AR26710[finu_la].mx-AR26710[finu_la].vx;
			
			I_LOVE_FIREFLY_FOREVER+=AR26710[finu_la].mx;
			fireflyIV[AR26710[finu_la].im]++;
//			printf("%lld %lld %lld\n",AR26710[finu_la].mx,AR26710[finu_la].vx,AR26710[finu_la].vy);
		}
		if(fireflyIV[1]<=n/2&&fireflyIV[2]<=n/2&&fireflyIV[3]<=n/2){
			cout<<I_LOVE_FIREFLY_FOREVER<<"\n";
			continue;
		}
		else{
			k=0;
//			cout<<I_LOVE_FIREFLY_FOREVER<<"\n";
			while(fireflyIV[++k]<=n/2);
//			cout<<k<<"\n";
			sort(AR26710+1,AR26710+n+1,cmp);
			for(int finu_la=1;finu_la<=n;finu_la++){
				if(!firefly_fly_on_fire__live_to_die[finu_la]&&AR26710[finu_la].im==k){
					firefly_fly_on_fire__live_to_die[finu_la]=1;
//					cout<<finu_la<<"\n";
					fireflyIV[k]--;
					I_LOVE_FIREFLY_FOREVER=I_LOVE_FIREFLY_FOREVER-AR26710[finu_la].mx+AR26710[finu_la].vx;
//					cout<<AR26710[finu_la].mx+AR26710[finu_la].vx<<"\n";
					if(fireflyIV[k]<=n/2){
						break;
					}
					fireflyIV[AR26710[finu_la].ix]++;
				}
//				printf("%lld %lld %lld\n",AR26710[finu_la].mx,AR26710[finu_la].vx,AR26710[finu_la].vy);
//				cout<<AR26710[finu_la].vx<<"\n";
			}
			cout<<I_LOVE_FIREFLY_FOREVER<<"\n";
		}
	}
	return 0;
} 
