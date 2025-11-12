#include<cstdio>
#include<algorithm>
using namespace std;
int a[5010],n;
int z[5010],c;
long long sum=0;
bool ok(int c){
    long long sum=0,ma=0;
    for(int i=1;i<=c;++i){
        sum+=z[i];
        ma=max(ma,(long long)z[i]);
    }
    return sum>2*ma;
}
//void prt(int s){
//    for(int i=1;i<=s;++i) printf("%d ",z[i]);
 //   printf("\n");
//}
long long zs(int s,int p,int d){// s mb n xz d 
    z[c++]=a[d];
    if(p==s+1){
    //    prt(s);
        --c;
        return ok(p);
    }else{
        
        long long t=0;
        for(int i=d+1;i<=n;++i){
            
            t+=zs(s,p+1,i);
            
        }
        --c;
        return t;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    if(n==3){
        printf("1");
        return 0;
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=3;i<=n;i++)
        sum+=zs(i,1,0);
    printf("%lld",sum%(998244353LL));
    return 0;
}