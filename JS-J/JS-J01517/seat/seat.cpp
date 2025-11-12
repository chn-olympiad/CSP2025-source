#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
bool cmp(int a,int b){
   return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int t=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            int num=(i-1)/n+1;
            int l;
            if(num&1)l=i-n*(num-1);
            else l=n-(i-n*(num-1))+1;
            printf("%d %d",num,l);
        }
    }
    return 0;
}
