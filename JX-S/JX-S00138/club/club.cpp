#include <bits/stdc++.h>
using namespace std;
const int N = 1E5+5;
int a[N][3], a1[N][3], a2[N][3], a3[N][3];
int l1 = 0, l2 = 0, l3 = 0;
int f(int n, int l){
    if(n == 1){
        l1++;
        a1[l1][1] = a[l][1];
        a1[l1][2] = a[l][2];
        a1[l1][3] = a[l][3];
    }
    else if(n==2){
        l2++;
        a2[l2][1] = a[l][1];
        a2[l2][2] = a[l][2];
        a2[l2][3] = a[l][3];
    }
    else{
        l3++;
        a3[l3][1] = a[l][1];
        a3[l3][2] = a[l][2];
        a3[l3][3] = a[l][3];
    }
    return 1;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
        for(int i = 1; i <= n; i++){
            int m = -1, mi, mn;
            if(max({a[i][1],a[i][2],a[i][3]}) == a[i][1]){ //a1
                if(l1 == 0) f(1, i);
                else{
                    if(l1 != n/2) f(1, i);
                    else{
                        for(int j = 1; j <= l1; j++){
                            int c = a1[j][1]-max(a1[j][2],a1[j][3]);
                            if(c < m){
                                m = c;
                                mi = j;
                                if(a1[j][2] >= a1[j][3]) mn = 2;
                                else mn = 3;
                            }
                        }
                        if(a1[i][1]-max(a1[i][2],a1[i][3]) >= m){
                            if(max(a1[mn][2], a1[mn][3]) == a1[mn][2]){
                                l2++;
                                a2[l2][1] = a1[mn][1];
                                a2[l2][2] = a1[mn][2];
                                a2[l2][3] = a1[mn][3];
                            }
                            else{
                                l3++;
                                a3[l3][1] = a1[mn][1];
                                a3[l3][2] = a1[mn][2];
                                a3[l3][3] = a1[mn][3];
                            }
                            f(1, i);
                        }
                        else{
                            if(max(a1[i][2], a1[i][3]) == a1[i][2]) f(2,i);
                            else f(3, i);
                        }
                    }
                }
            }
            else if(max({a[i][1],a[i][2],a[i][3]}) == a[i][2]){ //a2
                if(l2 == 0) f(2, i);
                else{
                    if(l2 != n/2) f(2, i);
                    else{
                        for(int j = 1; j <= l2; j++){
                            int c = a2[j][2]-max(a2[j][1],a2[j][3]);
                            if(c < m){
                                m = c;
                                mi = j;
                                if(a2[j][1] >= a2[j][3]) mn = 1;
                                else mn = 3;
                            }
                        }
                        if(a2[i][2]-max(a2[i][1],a2[i][3]) >= m){
                            if(max(a2[mn][1], a2[mn][3]) == a2[mn][1]){
                                l1++;
                                a1[l1][1] = a2[mn][1];
                                a1[l1][2] = a2[mn][2];
                                a1[l1][3] = a2[mn][3];
                            }
                            else{
                                l3++;
                                a3[l3][1] = a2[mn][1];
                                a3[l3][2] = a2[mn][2];
                                a3[l3][3] = a2[mn][3];
                            }
                            f(2, i);
                        }
                        else{
                            if(max(a2[i][1], a2[i][3]) == a2[i][1]) f(1,i);
                            else f(3, i);
                        }
                    }
                }
            }
            else{ //a3
                if(l3 == 0) f(3, i);
                else{
                    if(l3 != n/2) f(3, i);
                    else{
                        for(int j = 1; j <= l3; j++){
                            int c = a3[j][3]-max(a3[j][1],a3[j][2]);
                            if(c < m){
                                m = c;
                                mi = j;
                                if(a3[j][1] >= a3[j][2]) mn = 1;
                                else mn = 2;
                            }
                        }
                        if(a3[i][3]-max(a3[i][1],a3[i][2]) >= m){
                            if(max(a3[mn][1], a1[mn][2]) == a1[mn][2]){
                                l2++;
                                a2[l2][1] = a3[mn][1];
                                a2[l2][2] = a3[mn][2];
                                a2[l2][3] = a3[mn][3];
                            }
                            else{
                                l1++;
                                a1[l1][1] = a3[mn][1];
                                a1[l1][2] = a3[mn][2];
                                a1[l1][3] = a3[mn][3];
                            }
                            f(3, i);
                        }
                        else{
                            if(max(a3[i][1], a3[i][2]) == a1[i][1]) f(1,i);
                            else f(2, i);
                        }
                    }
                }
            }
        }
        long long sum = 0;
        for(int i = 1; i <= l1; i++){
            sum += a1[i][1];
        }
        for(int i = 1; i <= l2; i++){
            sum += a2[i][2];
        }
        for(int i = 1; i <= l3; i++){
            sum += a3[i][3];
        }
        memset(a, 0, sizeof a);
        memset(a1, 0, sizeof a1);
        memset(a2, 0, sizeof a2);
        memset(a3, 0, sizeof a3);
        l1 = l2 = l3 = 0;
    }
    return 0;
}
