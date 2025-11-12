#include<bits/stdc++.h>
using namespace std;
int t,n,mn,inf[5],infd;
const int maxn=200005;
struct tj{
	int dat,dir;//inf
};
struct st{
	int c[5],fts,stt;//val
	tj d[5];//val
	int chs,mov;//bool
}s[100005];
void qk(int x){
	for(int i=1;i<=x;i++)
		s[i].mov=s[i].fts=s[i].stt=s[i].chs=0;
	inf[1]=inf[2]=inf[3]=infd=0;//del all
}
bool cmp(tj a,tj b){
	return a.dat>b.dat;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		n=0;
		scanf("%d",&n);
		mn=n/2;
		qk(n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&s[i].c[1],&s[i].c[2],&s[i].c[3]);
			s[i].d[1].dat=s[i].c[1];s[i].d[1].dir=1;
			s[i].d[2].dat=s[i].c[2];s[i].d[2].dir=2;
			s[i].d[3].dat=s[i].c[3];s[i].d[3].dir=3;
			sort(s[i].d+1,s[i].d+4,cmp);
			s[i].chs=s[i].d[1].dir;
			s[i].fts=s[i].d[1].dat-s[i].d[2].dat;
			s[i].stt=s[i].d[2].dat-s[i].d[3].dat;
			inf[s[i].chs]++;
		}//input
		while(!(inf[1]<=mn&&inf[2]<=mn&&inf[3]<=mn))
			for(int i=1;i<=3;i++){
				while(inf[i]>mn){
					int mnn=maxn,mnw=0;
					for(int j=1;j<=n;j++){
						if(s[j].chs!=i||s[j].mov>=2)
							continue;
						if(s[j].mov==0){
							if(s[j].fts<mnn){
								mnn=s[j].fts;
								mnw=j;
							}
						}else if(s[j].mov==1){
							if(s[j].stt<mnn){
								mnn=s[j].stt;
								mnw=j;
							}
						}
					}
					inf[s[mnw].chs]--;
					s[mnw].chs=s[mnw].d[s[mnw].mov+2].dir;
					s[mnw].mov++;
					inf[s[mnw].chs]++;
				}
			}//try
		for(int i=1;i<=n;i++){
			infd+=s[i].c[s[i].chs];
		}
		printf("%d\n",infd);//output
	}
	return 0;
}
