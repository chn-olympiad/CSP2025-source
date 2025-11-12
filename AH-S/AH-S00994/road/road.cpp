#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <cstring>
#include <string>
using namespace std;

void read(int &x){
    bool flag=false;
    char read_c=0;
    x=0;
    while(read_c<'0'||read_c>'9'){
        if(read_c=='-') flag=true;
        read_c=getchar();
    }
    if(flag){
        while(read_c>='0'&&read_c<='9'){
            x=x*10+('0'-read_c);
            read_c=getchar();
        }
    }
    else{
        while(read_c>='0'&&read_c<='9'){
            x=x*10+(read_c-'0');
            read_c=getchar();
        }
    }
    return ;
}
const int N=1e4;
const int M=1e6;

int n,m,k;
int cnt;
int head[N+5];
int ass,bss,css;

struct www{
    int from,to,weight;

    bool operator < (const www x){
        return weight<x.weight;
    }

}edge[(M<<1)+5];
void add(int gfrom , int  gto , int gweight){
    cnt++;
    edge[cnt].from=gto;
    edge[cnt].weight=gweight;
    edge[cnt].to =head[gfrom];
    head[gfrom]=cnt;
}
bool gflag[N+5];
int rrr[N+5];
int ttt=0;
int nhk[15];
int nk[15][N+5];
void djstl(){
	while(ttt){
		for(int i=1;i<=n;i++){
			if(gflag[i]){
				gflag[i]=false;
				ttt--;
				for(int i=head[i];i;i=edge[head[i]].to){
					int tag=0;
					for(int j=1;i<=k;j++){
						if(nhk[j]+nk[j][i]+nk[j][edge[i].from]<rrr[edge[i].to]){
							rrr[edge[i].to]=nhk[j]+nk[j][i]+nk[j][edge[i].from];
							tag=j;
						}
					}
					if(rrr[edge[i].to]>edge[i].weight){
						tag=0;
						rrr[edge[i].to]=edge[i].weight;
						gflag[edge[i].to]=true;
						ttt++;
					}
					else if(tag){
						gflag[tag]=true;
						nhk[tag]=0;
						ttt++;
					}
				}
			}
		}
	}
	
}
int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    read(n);
    read(m);
    read(k);
    memset(rrr,0x3f,sizeof(rrr));
    for(int i=1;i<=m;i++){
        read(ass);
        read(bss);
        read(css);
        add(ass,bss,css);
        add(bss,ass,css);
    }
    for(int i=1;i<=k;i++){
        read(nhk[i]);
        for(int j=1;j<=n;j++){
            read(nk[i][j]);
        }
    }
    gflag[1]=true;
    ttt=1;
    djstl();
    int ans=0;
    for(int i=1;i<=n;i++){
		ans+=rrr[i];
	}
	cout<<ans;
    return 0;

}
