#include<bits/stdc++.h>
using namespace std;
#define N 100005
int T;
int n, ans;
struct member{
    int a1, a2, a3;
}a[N];
int mmax(int a, int b){
    return a>b?a:b;
}
bool cmp(member x, member y){
    return x.a1 > y.a1;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
        }
        if(n == 2){
            ans = mmax(mmax(a[1].a1+a[2].a2, a[1].a1+a[2].a3), mmax(mmax(a[1].a2+a[2].a1, a[1].a2+a[2].a3), mmax(a[1].a3+a[2].a1, a[1].a3+a[2].a2)));
        }
        else{
            sort(a+1, a+1+n, cmp);
            for(int i = 1; i <= n/2; i++){
                ans += a[i].a1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
