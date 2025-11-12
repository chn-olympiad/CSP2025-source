#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n,m;
struct qwq{
    int s,id;
} a[N];
bool cmp(qwq a,qwq b){
    return a.s > b.s;
}
int32_t main(){
    freopen("seat3.in","r",stdin);
    freopen("seat3.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    int len = n * m;
    for(int i = 1;i <= len;++i){
        scanf("%lld",&a[i].s);
        a[i].id = i;
    }
    sort(a + 1,a + len + 1,cmp);
    for(int i = 1;i <= len;++i){
        if(a[i].id == 1){
            if((i / n) % 2 == 1){
                if(i % n == 0){
                    printf("%lld %lld",i / n,n);
                }else{
                    printf("%lld %lld",i / n + 1,n - (i % n) + 1);
                }
            }else{
                if(i % m == 0){
                    printf("%lld 1",i / n);
                }else{
                    printf("%lld %lld",i / n + 1,i % n);
                }
            }
            break;
        }
    }
    return 0;
}
