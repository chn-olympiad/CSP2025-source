#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n,m;
int p[N];
int a[N][N];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int people = n * m;
    for(int i = 1;i <= people;i++){
        cin >> p[i];
    }
    if(n == 1 && m == 1){
        printf("1 1");
        return 0;
    }
    if(n == 1 && m > 1){
          int ans = p[1];
          sort(p + 1,p + people + 1,cmp);
          for(int j = 1;j <= people;j++){
                if(p[j] == ans){
                    printf("%d 1",j);
                    return 0;
                }
          }
    }
    if(n <= 10 && m == 1){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        for(int i = 1;i <= people;i++){
            if(p[i] == ans){
                printf("1 %d",i);
                return 0;
            }
        }
    }
    if(n == 2 && m == 2){
         int ans = p[1];
         sort(p + 1,p + people + 1,cmp);
         if(p[1] == ans){
            printf("1 1");
            return 0;
         }
         if(p[2] == ans){
            printf("1 2");
            return 0;
         }
         if(p[3] == ans){
            printf("2 2");
            return 0;
         }
         if(p[4] == ans){
            printf("2 1");
            return 0;
         }
    }
    if(n == 2 && m == 3){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("2 2");
            return 0;
        }
        if(p[4] == ans){
            printf("2 1");
            return 0;
        }
        if(p[5] == ans){
            printf("3 1");
            return 0;
        }
        if(p[6] == ans){
            printf("3 2");
            return 0;
        }
    }
    if(n == 2 && m == 4){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("2 2");
            return 0;
        }
        if(p[4] == ans){
            printf("2 1");
            return 0;
        }
        if(p[5] == ans){
            printf("3 1");
            return 0;
        }
        if(p[6] == ans){
            printf("3 2");
            return 0;
        }
        if(p[7] == ans){
            printf("4 2");
            return 0;
        }
        if(p[8] == ans){
            printf("4 1");
            return 0;
        }
    }
    if(n == 2 && m == 5){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("2 2");
            return 0;
        }
        if(p[4] == ans){
            printf("2 1");
            return 0;
        }
        if(p[5] == ans){
            printf("3 1");
            return 0;
        }
        if(p[6] == ans){
            printf("3 2");
            return 0;
        }
        if(p[7] == ans){
            printf("4 2");
            return 0;
        }
        if(p[8] == ans){
            printf("4 1");
            return 0;
        }
        if(p[9] == ans){
            printf("5 1");
            return 0;
        }
        if(p[10] == ans){
            printf("5 2");
        }
    }
    if(n == 2 && m == 6){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("2 2");
            return 0;
        }
        if(p[4] == ans){
            printf("2 1");
            return 0;
        }
        if(p[5] == ans){
            printf("3 1");
            return 0;
        }
        if(p[6] == ans){
            printf("3 2");
            return 0;
        }
        if(p[7] == ans){
            printf("4 2");
            return 0;
        }
        if(p[8] == ans){
            printf("4 1");
            return 0;
        }
        if(p[9] == ans){
            printf("5 1");
            return 0;
        }
        if(p[10] == ans){
            printf("5 2");
        }
        if(p[11] == ans){
            printf("6 2");
            return 0;
        }
        if(p[12] == ans){
            printf("6 1");
            return 0;
        }
    }
    if(n == 2 && m == 7){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("2 2");
            return 0;
        }
        if(p[4] == ans){
            printf("2 1");
            return 0;
        }
        if(p[5] == ans){
            printf("3 1");
            return 0;
        }
        if(p[6] == ans){
            printf("3 2");
            return 0;
        }
        if(p[7] == ans){
            printf("4 2");
            return 0;
        }
        if(p[8] == ans){
            printf("4 1");
            return 0;
        }
        if(p[9] == ans){
            printf("5 1");
            return 0;
        }
        if(p[10] == ans){
            printf("5 2");
        }
        if(p[11] == ans){
            printf("6 2");
            return 0;
        }
        if(p[12] == ans){
            printf("6 1");
            return 0;
        }
        if(p[13] == ans){
            printf("7 1");
            return 0;
        }
        if(p[14] == ans){
            printf("7 2");
            return 0;
        }
    }
    if(n == 2 && m == 8){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("2 2");
            return 0;
        }
        if(p[4] == ans){
            printf("2 1");
            return 0;
        }
        if(p[5] == ans){
            printf("3 1");
            return 0;
        }
        if(p[6] == ans){
            printf("3 2");
            return 0;
        }
        if(p[7] == ans){
            printf("4 2");
            return 0;
        }
        if(p[8] == ans){
            printf("4 1");
            return 0;
        }
        if(p[9] == ans){
            printf("5 1");
            return 0;
        }
        if(p[10] == ans){
            printf("5 2");
        }
        if(p[11] == ans){
            printf("6 2");
            return 0;
        }
        if(p[12] == ans){
            printf("6 1");
            return 0;
        }
        if(p[13] == ans){
            printf("7 1");
            return 0;
        }
        if(p[14] == ans){
            printf("7 2");
            return 0;
        }
        if(p[15] == ans){
            printf("8 2");
            return 0;
        }
        if(p[16] == ans){
            printf("8 1");
            return 0;
        }
    }
    if(n == 2 && m == 9){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("2 2");
            return 0;
        }
        if(p[4] == ans){
            printf("2 1");
            return 0;
        }
        if(p[5] == ans){
            printf("3 1");
            return 0;
        }
        if(p[6] == ans){
            printf("3 2");
            return 0;
        }
        if(p[7] == ans){
            printf("4 2");
            return 0;
        }
        if(p[8] == ans){
            printf("4 1");
            return 0;
        }
        if(p[9] == ans){
            printf("5 1");
            return 0;
        }
        if(p[10] == ans){
            printf("5 2");
        }
        if(p[11] == ans){
            printf("6 2");
            return 0;
        }
        if(p[12] == ans){
            printf("6 1");
            return 0;
        }
        if(p[13] == ans){
            printf("7 1");
            return 0;
        }
        if(p[14] == ans){
            printf("7 2");
            return 0;
        }
        if(p[15] == ans){
            printf("8 2");
            return 0;
        }
        if(p[16] == ans){
            printf("8 1");
            return 0;
        }
        if(p[17] == ans){
            printf("9 1");
            return 0;
        }
        if(p[18] == ans){
            printf("9 2");
            return 0;
        }
    }
    if(n == 2 && m == 10){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("2 2");
            return 0;
        }
        if(p[4] == ans){
            printf("2 1");
            return 0;
        }
        if(p[5] == ans){
            printf("3 1");
            return 0;
        }
        if(p[6] == ans){
            printf("3 2");
            return 0;
        }
        if(p[7] == ans){
            printf("4 2");
            return 0;
        }
        if(p[8] == ans){
            printf("4 1");
            return 0;
        }
        if(p[9] == ans){
            printf("5 1");
            return 0;
        }
        if(p[10] == ans){
            printf("5 2");
        }
        if(p[11] == ans){
            printf("6 2");
            return 0;
        }
        if(p[12] == ans){
            printf("6 1");
            return 0;
        }
        if(p[13] == ans){
            printf("7 1");
            return 0;
        }
        if(p[14] == ans){
            printf("7 2");
            return 0;
        }
        if(p[15] == ans){
            printf("8 2");
            return 0;
        }
        if(p[16] == ans){
            printf("8 1");
            return 0;
        }
        if(p[17] == ans){
            printf("9 1");
            return 0;
        }
        if(p[18] == ans){
            printf("9 2");
            return 0;
        }
        if(p[19] == ans){
            printf("10 2");
            return 0;
        }
        if(p[20] == ans){
            printf("10 1");
        }
    }
    if(n <= 10 && m == 2 && n != 2){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        int i2 = 1;
        for(int i = 1;i <= n;i++){
            a[i][1] = p[i2];
            i2++;
        }
        for(int i = n;i >= 1;i--){
            a[i][2] = p[i2];
            i2++;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(a[i][j] == ans){
                    printf("%d %d",j,i);
                    return 0;
                }
            }
        }
    }
    if(n == 3 && m == 3){
        int ans = p[1];
        sort(p + 1,p + people + 1,cmp);
        if(p[1] == ans){
            printf("1 1");
            return 0;
        }
        if(p[2] == ans){
            printf("1 2");
            return 0;
        }
        if(p[3] == ans){
            printf("1 3");
            return 0;
        }
        if(p[4] == ans){
            printf("2 3");
            return 0;
        }
        if(p[5] == ans){
            printf("2,2");
            return 0;
        }
        if(p[6] == ans){
            printf("2,1");
            return 0;
        }
        if(p[7] == ans){
            printf("3 1");
            return 0;
        }
        if(p[8] == ans){
            printf("3 2");
            return 0;
        }
        if(p[9] == ans){
            printf("3 3");
        }
    }
    return 0;
}
