#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int id,score;
}a[10005];
bool cmp(node a,node b){
    return a.score > b.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n*m;i++){
        scanf("%d",&a[i].score);
        a[i].id = i;
    }
    sort(a+1,a+n*m+1,cmp);
    int r_id;
    for(int i = 1;i <= n*m;i++){
        if(a[i].id == 1){
            r_id = i;
            break;
        }
    }
    int x = r_id % n,y = r_id / n;
    if(x == 0){
        x = n;
    } else {
        y++;
    }
    if(y % 2 == 0){
        x = n-x+1;
    }
    printf("%d %d",y,x);
    return 0;
}
