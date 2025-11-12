#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int t, n, ans, b[4], c[4];
// t:number of check part  n:number of people  ans:answer  b:satisfaction  c:number of people in every team
struct body// information to the club satisfaction of every person
{
    int a1, a2, a3;
}x[N];

void check(int num, body k[], int bi){// num:the stander  k:participation  bi:the number of all the people
    //edit 1
    if(c[1] > num || c[2] > num || c[3] > num){
        return;
    }
    //edit 2
    if(bi > num * 2){
        int z =  b[1] + b[2] + b[3];
        ans = max(ans, z);
        return;
    }
    //main way
    for(int i = 1; i <= 3; i ++){
        if(i = 1){
            b[1] += k[bi].a1;
            c[1] ++;
            check(num, k, bi + 1);
            b[1] -= k[bi].a1;
            c[1] --;
        }
        if(i = 2){
            b[2] += k[bi].a2;
            c[2] ++;
            check(num, k, bi + 1);
            b[2] -= k[bi].a2;
            c[2] --;
        }
        if(i = 3){
            b[3] += k[bi].a3;
            c[3] ++;
            check(num, k, bi + 1);
            b[3] -= k[bi].a3;
            c[3] --;
        }
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;
    //every part
    while(t){
        t --;
        //return
        ans = 0;
        //input
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%d%d%d", &x[i].a1, &x[i].a2, &x[i].a3);
        }
        //search
        check(n / 2, x, 1);
        //output
        printf("%d\n", ans);
    }
    return 0;
}
