#include <bits/stdc++.h>
using namespace std;

//Hi, smarty plants!
//Your zombie-zapping experience will get better
//with some behind-scenes updates and
//brain-picking animations

//Say goodbye to the long and winding road to unlock mini-games
//With this update,
//you can unlock each of them with coins separately.
//Don't wait for more
//Update now!

#define pr(fmt, arg...) //printf(fmt, ##arg)

int n, a[5008], b[5008], tail;
long long cnt;

int cmp(const void *p1, const void *p2){
    int *a = (int *)p1;
    int *b = (int *)p2;
    if(*a < *b){
        return 1;
    }
    return 0;
}

void dfs(int k, int m, int maxn, int sel){
    if(k >= n && sel >= 2){
        #if 0
        pr("Entered the ending\n");
        #endif
        if(m + a[k] > max(a[k], maxn) * 2){
            cnt++;
            #if 0
            pr("This could be a possible version, cnt = %lld\n", cnt);
            for(int i = 1; i <= tail; i++){
                pr("%d ", b[i]);
            }
            pr("%d", k);
            pr("\n");
            #endif
        }
        if(m > maxn * 2 && sel >= 3){
            cnt++;
            #if 0
            pr("Last one could be a possible version, cnt = %lld\n", cnt);
            for(int i = 1; i <= tail; i++){
                pr("%d ", b[i]);
            }
            pr("\n");
            #endif
        }
        return;
    }
    else if(k >= n && sel < 3){
        #if 0
        pr("Unexpected series contained less items than 3\n");
        #endif
        return;
    }
    else{
        #if 0
        pr("Entered selected items >= 2\n");
        #endif
        //if(m + a[k] > max(a[k], maxn) * 2 || sel <= 2){
            b[++tail] = k;
            dfs(k + 1, m + a[k], max(a[k], maxn), sel + 1);
            b[tail--] = 0;
            #if 0
            pr("Added into the series\n");
            #endif
        //}
        dfs(k + 1, m, maxn, sel);
        #if 0
        pr("Continued\n");
        #endif
    }
    return;
}


int main(){
    #if 1
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    #endif
    scanf("%d", &n);
    cnt = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        /*
        a[i] += a[i - 1];
        for(int j = 1; j <= i; j++){
            dp[j][i] = max(dp[j][i], a[i]);
            if(a[i] - a[j] >= )
        }
        */
    }
    //qsort(&a[1], n, 4, cmp);
    //pr("%d\n", n);
    tail = 0;
    dfs(1, 0, -1, 0);
    printf("%lld\n", cnt);
    return 0;
}