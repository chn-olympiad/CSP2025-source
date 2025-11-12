#include <bits/stdc++.h>
using namespace std;

int n;
int m1,m2;
int cj,id;
int a[10001];
int t = 0,s = 0;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&m1,&m2);
    n = m1 * m2;
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        if(i == 1) cj = a[i];
    }
    sort(a+1,a+n+1);
    for(int i = n;i >= 1;i--){
        if(a[i] == cj){
            id = n-i+1;
            break;
        }
    }
    if(id % m1 != 0)
        t = id / m1 + 1,s = id % m1;
    if(id % m1 == 0){
        t = id / m1,s = m1;
    }
    printf("%d ",t);
    if(t % 2 == 0){
        printf("%d\n",m1 - s + 1);
    }
    if(t % 2 == 1){
        printf("%d\n",s);
    }
    return 0;
}
