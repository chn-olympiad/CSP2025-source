#include<bits/stdc++.h>
using namespace std;
int t,n,ls;
int d[10005][5];
int all=0;
int bm[5];
struct need{
    int maxneed;
    int maxwhich;
}ne[10005];
struct bmens{
    int minneed=9e12+999;
    int minwhich;
    int max_wz;
    int maxmyd=0;
}wbm[5];
void whichmin(int wh){
wbm[wh].minneed=9e12+999;
	for(int i=1;i<=n;i++){
		if(d[i][wh]<wbm[wh].minneed && ne[i].maxwhich==wh && d[i][wh]!=0){
			wbm[wh].minneed=d[i][wh];
			wbm[wh].minwhich=i;
		}
	}
}
void whichmax(int wn){
wbm[wn].maxmyd=0;
	for(int i=1;i<=n;i++){
		if(d[i][wn]>wbm[wn].maxmyd && ne[i].maxwhich==wn){
			wbm[wn].max_wz=d[i][wn];
			wbm[wn].max_wz=i;
		}
	}
}
void fun(int x){
    ne[x].maxneed=0;
    if(d[x][1]>ne[x].maxneed){
    ne[x].maxneed=d[x][1];
    ne[x].maxwhich=1;
    }
    if(d[x][2]>ne[x].maxneed){
    ne[x].maxneed=d[x][2];
    ne[x].maxwhich=2;
    }
    if(d[x][3]>ne[x].maxneed){
    ne[x].maxneed=d[x][3];
    ne[x].maxwhich=3;
    }
    int k=ne[x].maxwhich;
    if(ne[x].maxneed==0){
    	whichmin(ne[x].maxwhich);
    	whichmax(ne[x].maxwhich);
    	int alc=9e12+999;
    	if(bm[1]<=alc){
    		k=1;
    		alc=bm[1];
		}
		if(bm[2]<=alc){
    		k=2;
    		alc=bm[2];
		}
		if(bm[3]<=alc){
    		k=3;
    		alc=bm[3];
		}
	}
    bm[k]++;
    all+=ne[x].maxneed;
    if(ne[x].maxneed<wbm[k].minneed){
        wbm[k].minneed=ne[x].maxneed;
        wbm[k].minwhich=x;
    }
    if(ne[x].maxneed>wbm[k].maxmyd){
        wbm[k].maxmyd=ne[x].maxneed;
        wbm[k].max_wz=x;
    }
    return;

}

void rep(int y){
    int s1,s2;
        if(y==1){
            s1=2;
            s2=3;
        }
        if(y==2){
            s1=1;
            s2=3;
        }
        if(y==3){
            s1=1;
            s2=2;
        }
     while(1){
        int m=wbm[y].max_wz;
        if((wbm[y].maxmyd>d[m][s1]+wbm[y].minneed) && (wbm[y].maxmyd>d[m][s2]+wbm[y].minneed)){
            ls=wbm[y].minwhich;
        }else{
            ls=m;
        }
        all-=d[ls][y];
        d[ls][y]=0;
        fun(ls);
        bm[y]-=1;
        if(bm[y]<=(n/2)) break;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i][1]>>d[i][2]>>d[i][3];
    }
    for(int i=1;i<=n;i++){
        fun(i);
    }
    if(bm[1]>(n/2)){
        rep(1);
    }
    if(bm[2]>(n/2)){
        rep(2);
    }
    if(bm[3]>(n/2)){
        rep(3);
    }
    cout<<all<<endl;
    all=0;
    bm[1]=0;
    bm[2]=0;
    bm[3]=0;
    wbm[1].minneed=9e12+999;
    wbm[2].minneed=9e12+999;
    wbm[3].minneed=9e12+999;
    wbm[1].maxmyd=0;
    wbm[2].maxmyd=0;
    wbm[3].maxmyd=0;
    }
    return 0;
}

