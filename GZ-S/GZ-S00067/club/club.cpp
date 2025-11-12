//GZ-S00067北京师范大学贵阳附属学校  刘锦宸
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,fen=0,g1=0,g2=0,g3=0;
		cin>>n;
		int man[n+1][4];
		int a1[n],a2[n],a3[n];
		memset(man,0,sizeof(man));
		for(int i=1;i<=n;i++){
			cin>>man[i][1]>>man[i][2]>>man[i][3];
			if(man[i][1]>=man[i][2]&&man[i][1]>=man[i][3]){
				a1[g1]=i;
				fen+=man[i][1];
				g1++;
			}
			else if(man[i][2]>=man[i][1]&&man[i][2]>=man[i][3]){
				a2[g2]=i;
				fen+=man[i][2];
				g2++;
			}
			else{
				a3[g3]=i;
				fen+=man[i][3];
				g3++;
			}
		}
		while(g1>n/2){
			int wei=0,mi=30000,l=-1;
			bool z=false;
			for(int i=0;i<g1;i++){
				if(a1[i]==-1)continue;
				int shu2=man[a1[i]][1]-man[a1[i]][2];
				int shu3=man[a1[i]][1]-man[a1[i]][3];
				if(g2<n/2&&g3>=n/2&&shu2<mi){
				wei=2;mi=shu2;l=i;}
				else if(g2>=n/2&&g3<n/2&&shu3<mi){
					wei=3;mi=shu3;l=i;
				}
				else if(g2<n/2&&g3<n/2){
					if(shu2<shu3&&shu2<mi){wei=2;mi=shu2;l=i;
					}
					else if(shu2>shu3&&shu3<mi){wei=3;mi=shu3;l=i;
					}
					else if(shu2==shu3&&shu2<mi){mi=shu2;l=i;z=true;
					}
				}
			}
			g1--;fen-=mi;a1[l]=-1;
			if(!z){
				if(wei==2)g2++;else if(wei==3)g3++;
			}
			
		}
		while(g2>n/2){
			int wei=0,mi=30000,l=-1;
			bool z=false;
			for(int i=0;i<g2;i++){
				if(a2[i]==-1)continue;
				int shu1=man[a2[i]][2]-man[a2[i]][1];
				int shu3=man[a2[i]][2]-man[a2[i]][3];
				if(g1<n/2&&g3>=n/2&&shu1<mi){wei=1;mi=shu1;l=i;
				}
				else if(g1>=n/2&&g3<n/2&&shu3<mi){wei=3;mi=shu3;l=i;
				}
				else if(g1<n/2&&g3<n/2){
					if(shu1<shu3&&shu1<mi){wei=1;mi=shu1;l=i;
					}
					else if(shu1>shu3&&shu3<mi){wei=3;mi=shu3;l=i;
					}
					else if(shu1==shu3&&shu1<mi){wei=1;mi=shu1;l=i;z=true;
					}
				}
			}
			g2--;fen-=mi;a2[l]=-1;
			if(!z){
				if(wei==1)g1++;else if(wei==3)g3++;
			}
		}
		while(g3>n/2){
			int wei=0,mi=30000,l=-1;
			bool z=false;
			for(int i=0;i<g3;i++){
				if(a3[i]==-1)continue;
				int shu2=man[a3[i]][3]-man[a3[i]][2];
				int shu1=man[a3[i]][3]-man[a3[i]][1];
				if(g2<n/2&&g1>=n/2&&shu2<mi){wei=2;mi=shu2;l=i;
				}
				else if(g2>=n/2&&g1<n/2&&shu1<mi){wei=1;mi=shu1;l=i;
				}
				else if(g2<n/2&&g1<n/2){
					if(shu2<shu1&&shu2<mi){wei=2;mi=shu2;l=i;
					}
					else if(shu2>shu1&&shu1<mi){wei=1;mi=shu1;l=i;
					}
					else if(shu2==shu1&&shu2<mi){wei=2;mi=shu2;l=i;z=true;
					}
				}
			}
			g3--;fen-=mi;a3[l]=-1;
			if(!z){
				if(wei==2)g2++;else if(wei==1)g1++;
			}
		}
		cout<<fen<<endl;
	}
	return 0;
} 
