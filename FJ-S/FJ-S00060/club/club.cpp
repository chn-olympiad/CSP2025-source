#include <bits/stdc++.h>
#include <cstdio>
#define int long long
using namespace std;
int T;
int n;
struct mem{
	int x;
	int y;
	int z;
	bool operator <(const mem &oth)const{
		return max({x,y,z})>max({oth.x ,oth.y ,oth.z });
	}
}a[100005];
struct mema{
	int x;
	int y;
	int z;
	bool operator <(const mema &oth)const{
		return x-max(y,z)>oth.x -max(oth.y ,oth.z );
	}
};
struct memb{
	int x;
	int y;
	int z;
	bool operator <(const memb &oth)const{
		return y-max(x,z)>oth.y -max(oth.x ,oth.z );
	}
};
struct memc{
	int x;
	int y;
	int z;
	bool operator <(const memc &oth)const{
		return z-max(x,y)>oth.z -max(oth.x ,oth.y );
	}
};
int suma,sumb,sumc;
int p;
int ans=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x >>a[i].y >>a[i].z ;
		}		
		p=n/2;
		suma=0;
		sumb=0;
		sumc=0;
		ans=0;
		sort(a+1,a+n+1);
		priority_queue<mema>qa;
		priority_queue<memb>qb;
		priority_queue<memc>qc;
		for(int i=1;i<=n;i++){
			int ma,mb,mc;
			ma=a[i].x ;
			mb=a[i].y ;
			mc=a[i].z ;
			if(ma==mb && mb==mc){
				if(suma<=sumb && suma<=sumc){
					suma++;
					mema pu={ma,mb,mc};
					qa.push(pu);
					ans+=ma;
				}else if(sumb<=suma && sumb<=sumc){
					sumb++;
					memb pu={ma,mb,mc};
					qb.push(pu);
					ans+=mb;
				}else if(sumc<=suma && sumc<=sumb){
					sumc++;
					memc pu={ma,mb,mc};
					qc.push(pu);
					ans+=mc;
				}
			}else if(ma==mb && ma>mc){
				if(suma<=sumb){
					suma++;
					mema pu={ma,mb,mc};
					qa.push(pu);
					ans+=ma;
				}else if(sumb<=suma){
					sumb++;
					memb pu={ma,mb,mc};
					qb.push(pu);
					ans+=mb;
				}
			}else if(ma==mc && ma>mb){
				if(suma<=sumc){
					suma++;
					mema pu={ma,mb,mc};
					qa.push(pu);
					ans+=ma;
				}else if(sumc<=suma){
					sumc++;
					memc pu={ma,mb,mc};
					qc.push(pu);
					ans+=mc;
				}
			}else if(mb==mc && mb>ma){
				if(sumb<=sumc){
					sumb++;
					memb pu={ma,mb,mc};
					qb.push(pu);
					ans+=mb;
				}else if(sumc<=sumb){
					sumc++;
					memc pu={ma,mb,mc};
					qc.push(pu);
					ans+=mc;
				}
			}else if(ma>=mb && ma>=mc){
				if(suma<p){
					suma++;
					ans+=ma;
					mema pu={ma,mb,mc};
					qa.push(pu);
					continue;
				}else{
					mema now=qa.top();
					if(ma-max(mb,mc)>now.x -max(now.y ,now.z )){
						qa.pop();
						mema pus={ma,mb,mc};
						qa.push(pus);
						ans-=now.x ;
						ans+=ma;
						if(now.y ==now.z ){
							if(sumb<sumc){
								sumb++;
								memb pu={now.x ,now.y ,now.z };
								qb.push(pu);
								ans+=now.y ;
							}else{
								sumc++;
								memc pu={now.x ,now.y ,now.z };
								qc.push(pu);
								ans+=now.z ;
							}
						}else if(now.y >=now.z ){
							sumb++;
							memb pu={now.x ,now.y ,now.z };
							qb.push(pu);
							ans+=now.y ;
						}else if(now.z >=now.y ){
							sumc++;
							memc pu={now.x ,now.y ,now.z };
							qc.push(pu);
							ans+=now.z ;
						}
						continue;
					}
				}
				if(mb>=mc){
					sumb++;
					memb pu={ma,mb,mc};
					qb.push(pu);
					ans+=mb;
				}else if(mc>=mb){
					sumc++;
					memc pu={ma,mb,mc};
					qc.push(pu);
					ans+=mc;
				}
			}else if(mb>=ma && mb>=mc){
				if(sumb<p){
					sumb++;
					ans+=mb;
					memb pu={ma,mb,mc};
					qb.push(pu);
					continue;
				}else{
					memb now=qb.top();
					if(mb-max(ma,mc) >now.y-max(now.x ,now.z )){
						qb.pop();
						memb pus={ma,mb,mc};
						qb.push(pus);
						ans-=now.y ;
						ans+=mb;
						if(now.x ==now.z ){
							if(suma<sumc){
								suma++;
								mema pu={now.x ,now.y ,now.z };
								qa.push(pu);
								ans+=now.x ;
							}else{
								sumc++;
								memc pu={now.x ,now.y ,now.z };
								qc.push(pu);
								ans+=now.z ;
							}
						}else if(now.x >=now.z ){
							suma++;
							mema pu={now.x ,now.y ,now.z };
							qa.push(pu);
							ans+=now.x ;
						}else if(now.z >=now.x ){
							sumc++;
							memc pu={now.x ,now.y ,now.z };
							qc.push(pu);
							ans+=now.z ;
						}
						continue;
					}
				}
				if(ma>=mc){
					suma++;
					mema pu={ma,mb,mc};
					qa.push(pu);
					ans+=ma;
				}else if(mc>=ma){
					sumc++;
					memc pu={ma,mb,mc};
					qc.push(pu);
					ans+=mc;
				}
			}else if(mc>=ma && mc>=mb){
				if(sumc<p){
					sumc++;
					memc pu={ma,mb,mc};
					qc.push(pu);
					ans+=mc;
					continue;
				}else{
					memc now=qc.top();
					if(mc-max(mb,ma)>now.z -max(now.y ,now.x )){
						qc.pop();
						memc pus={ma,mb,mc};
						qc.push(pus);
						ans-=now.z ;
						ans+=mc;
						if(now.y ==now.x ){
							if(sumb<suma){
								sumb++;
								memb pu={now.x ,now.y ,now.z };
								qb.push(pu);
								ans+=now.y ;
							}else{
								suma++;
								mema pu={now.x ,now.y ,now.z };
								qa.push(pu);
								ans+=now.x ;
							}
						}else if(now.y >=now.x ){
							sumb++;
							memb pu={now.x ,now.y ,now.z };
							qb.push(pu);
							ans+=now.y ;
						}else if(now.x >=now.y ){
							suma++;
							mema pu={now.x ,now.y ,now.z };
							qa.push(pu);
							ans+=now.x ;
						}
						continue;
					}
				}
				if(ma>=mb){
					suma++;
					mema pu={ma,mb,mc};
					qa.push(pu);
					ans+=ma;
				}else if(mb>=ma){
					sumb++;
					memb pu={ma,mb,mc};
					qb.push(pu);
					ans+=mb;
				}
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
