#include <bits/stdc++.h>
using namespace std;
int n;
int T;
typedef struct lub{
	int peo;
	int num;
}Club;
Club club[10010],club2[10010],club3[10010];
int clubs[3];
bool cmp(Club c1,Club c2){
	return c1.num>c2.num;
}
bool check(int a){
	int zn=0;
	if(club[a].num==0){
		zn++;
	}
	if(club2[a].num==0){
		zn++;
	}
	if(club3[a].num==0){
		zn++;
	}
	return zn==2;
}
int caozuo(int a){
	int nb=6;
	if(club[a].num==0){
                nb-=1;
        }
        if(club2[a].num==0){
                nb-=2;
        }
        if(club3[a].num==0){
                nb-=3;
        }
	return nb;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		clubs[1]=clubs[2]=clubs[3]=0;
		for(int i=1;i<=10010;i++){
			club[i].peo=club2[i].peo=club3[i].peo=i;
			club[i].num=club2[i].num=club3[i].num=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>club[i].num>>club2[i].num>>club3[i].num;
		}
		for(int i=n;i>1;i--){
			if(check(i)){
				if(caozuo(i)==1&&!check(i-1)){
					club[i-1].num=0;
				}
				else if(caozuo(i)==2&&!check(i-1)){
					club2[i-1].num=0;
				}
				else if(caozuo(i)==3&&!check(i-1)){
					club3[i-1].num=0;
				}
			}
		}
		sort(club+1,club+1+n,cmp);
		sort(club2+1,club2+1+n,cmp);
		sort(club3+1,club3+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n/2;j++){
				if(club[i].peo==club2[j].peo){
					if(club[i].num>club2[j].num){
						club2[j].num=0;
					}
					else{
						club[i].num=0;
					}
				}
			}
		}
		for(int i=1;i<=n/2;i++){
                        for(int j=1;j<=n/2;j++){
                                if(club[i].peo==club3[j].peo){
                                        if(club[i].num>club3[j].num){
                                                club3[j].num=0;
                                        }
                                        else{
                                                club[i].num=0;
                                        }
                                }
                        }
                }
		for(int i=1;i<=n/2;i++){
                        for(int j=1;j<=n/2;j++){
                                if(club2[i].peo==club3[j].peo){
                                        if(club2[i].num>club3[j].num){
                                                club3[j].num=0;
                                        }
                                        else{
                                                club2[i].num=0;
                                        }
                                }
                        }
                }
		for(int i=n/2+1;i<=n;i++){
			club[i].num=0;
		}
		for(int i=n/2+1;i<=n;i++){
                        club2[i].num=0;
                }
		for(int i=n/2+1;i<=n;i++){
                        club3[i].num=0;
                }
		for(int i=1;i<=n/2;i++){
			if(club[i].num==0){
				continue;
			}
			clubs[1]+=club[i].num;
		}
		for(int i=1;i<=n/2;i++){
                        if(club2[i].num==0){
                                continue;
                        }
                        clubs[2]+=club2[i].num;
                }
		for(int i=1;i<=n/2;i++){
                        if(club3[i].num==0){
                                continue;
                        }
                        clubs[3]+=club3[i].num;
              	}
		cout<<clubs[1]+clubs[2]+clubs[3]<<endl;
	}
	return 0;
}
