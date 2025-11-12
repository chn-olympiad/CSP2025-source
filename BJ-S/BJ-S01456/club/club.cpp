#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
using namespace std;

int T, n;

struct stu{
    int score[3] = {0};
    int fav[3] = {0};
    int total_score = 0;
    bool stay = 0;
}a[100005];

bool cmp(stu x, stu y){
    return x.total_score < y.total_score;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> T;

    while(T--){
        int ans = 0;
        int c[3] = {0};
        int p[3] = {0};
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i].score[0] >> a[i].score[1] >> a[i].score[2];
            a[i].total_score = a[i].score[0] + a[i].score[1] + a[i].score[2];
            a[i].stay = 1;
            if(a[i].score[0] > a[i].score[1] && a[i].score[0] > a[i].score[2]){
                a[i].fav[0] = 0;
                if(a[i].score[1] > a[i].score[2]){
                    a[i].fav[1] = 1;
                    a[i].fav[2] = 2;
                }
                else{
                    a[i].fav[1] = 2;
                    a[i].fav[2] = 1;
                }
            }
            if(a[i].score[1] > a[i].score[0] && a[i].score[1] > a[i].score[2]){
                a[i].fav[0] = 1;
                if(a[i].score[0] > a[i].score[2]){
                    a[i].fav[1] = 0;
                    a[i].fav[2] = 2;
                }
                else{
                    a[i].fav[1] = 2;
                    a[i].fav[2] = 0;
                }
            }
            if(a[i].score[2] > a[i].score[1] && a[i].score[2] > a[i].score[0]){
                a[i].fav[0] = 2;
                if(a[i].score[0] > a[i].score[1]){
                    a[i].fav[1] = 0;
                    a[i].fav[2] = 1;
                }
                else{
                    a[i].fav[1] = 1;
                    a[i].fav[2] = 0;
                }
            }
            c[0] = max(c[0], a[i].score[0]);
            c[1] = max(c[1], a[i].score[1]);
            c[2] = max(c[2], a[i].score[2]);
        }

        sort(a, a + n, cmp);

        int remain = n;
        while(remain){
            for(int i = 0; i < n; i++){
                if(a[i].score[a[i].fav[0]] == c[a[i].fav[0]] && p[a[i].fav[0]] <= n / 2 && a[i].stay == 1){
                    a[i].stay = 0;
                    ans += a[i].score[a[i].fav[0]];
                    remain--;
                    p[a[i].fav[0]]++;
                }
                else if(a[i].score[a[i].fav[1]] == c[a[i].fav[1]] && p[a[i].fav[1]] <= n / 2 && a[i].stay == 1){
                    a[i].stay = 0;
                    ans += a[i].score[a[i].fav[1]];
                    remain--;
                    p[a[i].fav[1]]++;
                }
                else if(a[i].score[a[i].fav[2]] == c[a[i].fav[2]] && p[a[i].fav[2]] <= n / 2 && a[i].stay == 1){
                    a[i].stay = 0;
                    ans += a[i].score[a[i].fav[2]];
                    remain--;
                    p[a[i].fav[2]]++;
                }
                else{
                    continue;
                }
            }
            c[0]--;c[1]--;c[2]--;
        }
        cout << ans << endl ;
    }

    return 0;
}