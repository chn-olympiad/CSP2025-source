#include<bits/stdc++.h>
using namespace std;
struct stu{
    int sco;
    bool is;
}a[110];
int n,m;
bool cmp(stu x,stu y){
    return x.sco>y.sco;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i].sco);
        if(i==1) a[i].is=true;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(!a[i].is) continue;
        if((i+n-1)/n%2==1){
            if(i%n==0) printf("%d %d",(i+n-1)/n,n);
            else printf("%d %d",(i+n-1)/n,i%n);
        }else{
            if(i%n==0) printf("%d 1",(i+n-1)/n);
            else printf("%d %d",(i+n-1)/n,n-i%n+1);
        }
    }
    return 0;
}
