#include <bits/stdc++.h>
using namespace std;
int a[110];
int n,m,c=1,r=1,cnt=0,q=0;
int main () {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    cnt=a[1];
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++){
        if(cnt==a[i]){
            cnt=i;
            break;
        }
    }
    for(int i=n*m;i>0;i--){
        if(cnt==i)break;
        if(q==0){
            c++;
        }
        else{
            c--;
        }
        if(c>n){
            c=n;
            r++;
            q=(q+1)%2;
        }
        else if(c==0){
            c=1;
            r++;
            q=(q+1)%2;
        }
    }
    printf("%d %d\n",r,c);
    //printf("%d\n",cnt);
    return 0;
}