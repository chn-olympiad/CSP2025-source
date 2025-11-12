#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[10005];
long long s[105][105];
long long c,r;

bool cmp(long long a,long long b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    long long nm = n * m;
    for (int i = 1;i <= nm;i++){
        scanf("%lld",&a[i]);
    }
    long long tmp = a[1];
    sort(a + 1,a + nm + 1,cmp);
    long long x = 1,y = 1;
    int d = 1;
    for (int i = 1;i <= nm;i++){
        if (x >= 1 && x <= n && y >= 1 && y <= m){
            s[x][y] = a[i];
            if (tmp == s[x][y]){
                r = x,c = y;
                break;
            }
        }
        if (d == 1){
            x++;
            if (x == n){
                d = 2;
            }
        }else if (d == 2){
            y++;
            if (x == n){
                d = 3;
            }else{
                d = 1;
            }
        }else if (d == 3){
            x--;
            if (x == 1){
                d = 2;
            }
        }
    }
    printf("%lld %lld",c,r);
    return 0;
}
