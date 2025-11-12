#include<bits/stdc++.h>
using namespace std;
int n, t;
int a[100000][3], s1 = 0, s2 = 0, s3 = 0, s_all = 0;
int myd_i (int y){
    return max(a[y-1][0], max(a[y-1][1], a[y-1][2]));
}
int myd_id (int x){
    int sum = 0;
    if((a[x-1][0] == myd_i(x)) && (a[x-1][1] != myd_i(x)) && (a[x-1][2] != myd_i(x))) return 1;
    else{
        if((a[x-1][1] == myd_i(x)) && (a[x-1][0] != myd_i(x)) && (a[x-1][2] != myd_i(x))) return 2;
        else{
            if((a[x-1][2] == myd_i(x)) && (a[x-1][0] != myd_i(x)) && (a[x-1][1] != myd_i(x))) return 3;
            else{
                for(int i = 0; i <= 2; i++){
                    if(a[x-1][i] == myd_i(x)) sum++;
                }
                return sum;
            }
        }
    }
}
int main (){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            for(int u = 0; u <= 2; u++){
                scanf("%d", &a[j][u]);
            }
            if(myd_id(j) == 1) s1++, s_all += myd_i(j);
            if(myd_id(j) == 2) s2++, s_all += myd_i(j);
            if(myd_id(j) == 3) s3++, s_all += myd_i(j);
            if(myd_id(j) >= 4){
                s_all += myd_i(j);
                int maybe[myd_id(j)];
                int c = 0;
                for(int x = 0; x <= 2; x++){
                    if(a[j][x] == myd_i(j)) maybe[c] = x;
                    c++;
                }
            }
            int s_min = min(s1, min(s2, s3));
            if(s_min == s1) s1++;
            else if(s_min == s2) s2++;
            else if(s_min == s3) s3++;
        }
        if(max(s1, max(s2, s3)) <= n/2) printf("%d\n", s_all);
    }
    return 0;
}
