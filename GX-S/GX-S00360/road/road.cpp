#include<bits/stdc++.h>
using namespace std;

const int N = 10000+10,M=1000000+10;
int n,m,t;
long long as;
long long c[20],a[20][N];
struct edge{
    long long W;
    int To,From;
}E[2*M+10*N*2];
int Begin[N+10],etot;
void add(int x,int y,long long z){
    E[++etot].From = x;
    E[etot].To = y;
    E[etot].W = z;
}
int f[N+10];
int fidf(int x){
    if(f[x] == x) return x;
    else return f[x] = fidf(f[x]);
}
int pw[20];
bool cmp(edge x,edge y){ return x.W<y.W; }

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int x,y;
    long long z;
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lld",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=t;i++){
        scanf("%lld",&z);
        c[i] = z;
        for(int j=1;j<=n;j++){
            scanf("%lld",&z);
            a[i][j] = z;
            add(n+i,j,z);
            add(j,n+i,z);
        }
    }
    pw[0] = 1;
    for(int i=1;i<=13;i++){
        pw[i] = pw[i-1]*2;
    }

    as = 1e18;
    long long cbas=0,cb=0;
    sort(E+1,E+etot+1,cmp);
    for(int S=0;S<pw[t];S++){
        cbas = 0;cb = n;
        for(int i=1;i<=t;i++){
            if(S&(1<<(i-1))){
                cbas += c[i];
                cb++;
            }
        }
        for(int i=1;i<=n+t;i++){
            f[i] = i;
        }
        for(int i=1;i<=etot;i++){
            if(!(E[i].From>n && E[i].To>n)){
                if(!((E[i].From>n) && ((S&(1<<(E[i].From-n-1)))==0))  &&  !((E[i].To>n) && ((S&(1<<(E[i].To-n-1)))==0))  && fidf(E[i].From)!=fidf(E[i].To)){
                    /*if(S == 0){
                        printf("add (%d,%d)\n",E[i].From,E[i].To);
                        //printf("%d cke\n",(S & (1<< 6-4-1)) == 0);
                    }*/
                    f[fidf(E[i].From)] = fidf(E[i].To);
                    cbas += E[i].W;
                    cb--;
                }
            }
            if(cb == 1) break;
        }
        /*if(as> cbas){
            printf("now S %d\n",S);
        }*/
        as = min(as,cbas);
    }

    printf("%lld\n",as);
    return 0;
}
