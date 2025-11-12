#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int n,m,k;
int a[N],b,rnk;
int x,y;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    k = n * m;
    for(int i = 1;i <= k;++ i)
        scanf("%d",&a[i]);
    b = a[1];
    sort(a + 1,a + 1 + k,greater<int>());
    for(int i = 1;i <= k;++ i)
        if(a[i] == b) rnk = i;
    int cnt = 0;
    bool flag = 0;
    // printf("rnk : %d\n",rnk);
    for(int i = 1;i <= m;++ i){
        ++ x;
        for(int j = 1;j <= n;++ j){
            ++ cnt;
            if(cnt % n != 1 || i == 1){
                if(i % 2 == 1) ++ y;
                else -- y;
            }
            if(cnt == rnk){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    printf("%d %d",x,y);
    return 0;
}