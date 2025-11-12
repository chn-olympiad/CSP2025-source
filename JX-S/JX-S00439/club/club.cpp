#include <iostream>
#include <cstdio>
#include <algorithm>
#define M 200005
using namespace std;
struct node{
    int id, r[4], amax;
}a[M];
long ans[8];
int n, t, d[4];
int mx(int b1, int b2, int b3){
    int m=0;
    if(b1 > m) m=b1;
    if(b2 > m) m=b2;
    if(b3 > m) m=b3;
    if(b1 == m) return 1;
    else if(b2 == m) return 2;
    else if(b3 == m) return 3;
}
bool cmp(node x, node y){
    return x.r < y.r;
    //f(x.amax == y.amax) return x.r < y.r;
    //return x.id < y.id;
}
bool p(int  x, int y){
    return a[x].r[a[x].amax] < a[y].r[a[y].amax];
}
void max_exchange(){
    sort(a,a+n,cmp);
    int k1[M/2],k2[M/2],k3[M/2];
    int kk1=0, kk2=0, kk3=0;
    for(int i=0 ; i <= n ; i++){
        if(a[i].amax == 1){
            k1[kk1]=a[i].id;
            kk1++;
        }
        else if(a[i].amax == 2){
            k2[kk2]=a[i].id;
            kk2++;
        }
        else if(a[i].amax == 3){
            k3[kk3]=a[i].id;
            kk3++;
        }
    }
    sort(k1,k1+M/2,p);
    sort(k2,k2+M/2,p);
    sort(k3,k3+M/2,p);
    while(1){

    }
}
int main (){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for( int l=1 ; l <= t ; l++) {
        cin >> n;
        for(int i = 0 ; i < n ; i++) {
            a[i].id=i+1;
            scanf("%d%d%d", &a[i].r[1], &a[i].r[2], &a[i].r[3]);
            a[i].amax=mx(a[i].r[1], a[i].r[2], a[i].r[3]);
        }
       // max_exchange();
        sort(a,a+n,cmp);
        for(int i=0 ; i < n ; i++) {
            if(d[a[i].amax] <= n/2) {
                d[a[i].amax]++;
                ans[l]+=a[i].r[a[i].amax];
            }
        }
    }
    for( int l=1 ; l <= t ; l++)
        cout << ans[l] << endl;
    return 0;
}
