#include<cstdio>
#include<algorithm>
using namespace std;
int st[110],ans[2];
int n,m;
void wz(int a){
//    printf("%d",a);
    int f=(a%(2*n)),l=(a/n+1);
    ans[1]=l;
    if(f<=n&&f) ans[0]=f;
    else ans[0]=2*n-f+1;
}
bool cmp(int a,int b){return a>b;}
int main(){//g++ -o seat seat.cpp
   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int d;
    scanf("%d",&d);
    st[1]=d;
    for(int i=2;i<=n*m;++i){
        scanf("%d",&st[i]);    
    }
  
    sort(st+1,st+1+n*m,cmp);
    int x;
    for(x=1;x<=n*m;++x){
  //      printf("%d ",st[x]);
        if(st[x]==d){
            break;
        }
    }
        
    wz(x);
    printf("%d %d\n",ans[1],ans[0]);
    return 0;
}