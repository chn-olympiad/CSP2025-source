#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int c,int d){
    return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int now=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==now){
            now=i;
            break;
        }
    }
    int t=(now-1)/n+1;
    int s=(now-1)%n+1;
    if(t%2==0){
        s=n-s+1;
    }
    printf("%d %d\n",t,s);
    return 0;
}

