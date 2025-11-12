#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
    int sc,id;
} a[110];
bool cmp(stu a,stu b){
    return a.sc > b.sc;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++){
        scanf("%d",&a[i].sc);
        a[i].id = i;
    }
    sort(a + 1,a + n*m + 1,cmp);
    int now;
    for(int i = 1;i <= n*m;i++)
        if(a[i].id == 1){
            now = i;
            break;
        }
    int f = now / (2 * n);
    int g = now % (2 * n);
    int x,y;
    if(g <= n){
        x = f * 2 + 1;
        y = g;
    }else{
        x = f * 2 + 2;
        y = 2 * n - g + 1;
    }
    printf("%d %d",x,y);
}
