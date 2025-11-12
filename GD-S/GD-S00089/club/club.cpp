#include<bits\stdc++.h>
using namespace std;
using ll = long long;

struct p{
	ll a1,a2,a3,lose;
};

p m[100010];//member

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;cin>>t;
	for(int k = 0;k<t;k++){
		vector<ll>club[4]; 
		//ll club[4] = {0,0,0,0};
		ll n;cin>>n;
		ll sum = 0;
		int over_club = 0;
		for(ll i = 0;i<n;i++){
			ll r1,r2,r3;
			
			scanf("%lld",&r1);scanf("%lld",&r2);scanf("%lld",&r3);
			
			if(r1>=r2 && r1>=r3){//max a1
				sum+=r1;
				ll min_lose = r2>r3?r1-r2:r1-r3;  //	取lose最小值 
				club[1].push_back({min_lose});
			}
			else if(r2>=r3 && r2>=r1){//max a2
				sum+=r2;
				ll min_lose = r1>r3?r2-r1:r2-r3;  //	取lose最小值 
				club[2].push_back({min_lose});
			}
			else if(r3>=r2 && r3>=r1){//max a3
				sum+=r3;
				ll min_lose = r2>r1?r3-r2:r3-r1;  //	取lose最小值 
				club[3].push_back({min_lose});
			}
			
		}
		
		for(int i = 1;i<=3;i++){
			if(club[i].size() <= n/2)continue;
			
			sort(club[i].begin(),club[i].end());
			ll j=0;
			//cout<<"sum "<<sum<<endl;////
			ll s = club[i].size();
			while(s > n/2){
				//cout<<"lose "<<club[i][j]<<' ';////
				sum-=club[i][j];
				j+=1;
				s-=1;
			}
			break;
		}
		
		printf("%lld\n",sum);
	}
	return 0;
}
