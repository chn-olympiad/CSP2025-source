#include <bits/stdc++.h>
using namespace std;

int n, m, a[105];
int R_score, R_th; //R_th is to record which "th"(or"st", "nd", "rd") R got.
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d %d", &n, &m);
    int nxm_value = n*m;
    for (int i = 1; i <= nxm_value; i++){
        scanf("%d", &a[i]);
    }
    R_score = a[1];

    sort(a+1, a+nxm_value+1, greater<int>());
    for (int i = 1; i <= nxm_value; i++){
        if (a[i] == R_score){
            R_th = i;
            break;
        }
    }

    if (R_th%n == 0){
        printf("%d %d", R_th/n, ((R_th/n)%2 == 0? 1 : n));
    }else{
        //if the value below is a OUSHU, it means R should be in the JISHU LIE.
        if ((R_th/n)%2 == 0){
            printf("%d %d", (R_th/n+1), (R_th%n));
        }else{
            printf("%d %d", (R_th/n+1), (n-R_th%n+1));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
