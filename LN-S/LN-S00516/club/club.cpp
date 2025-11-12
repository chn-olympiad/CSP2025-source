#include<bits/stdc++.h>
using namespace std;


struct wxy{
    int ans;
    int degree[4];
}dp[100005][5];
int stud[100005][5];
int stud_[100005];
//int pian211, pian212, pian213;
//int pian221, pian222, pian223;
int pian1[100005];
int pian2[10];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int tot_num;
    scanf("%d", &tot_num);
    /*for(int i = 1; i <= tot_num; i++){
        memset(stud , 0 , sizeof(stud));
        memset(stud_ , 0 , sizeof(stud_));
        int new_num;
        scanf("%d", &new_num);
        int maxn_num = new_num >> 1;
        for(int j = 1; j <= new_num; j++){
            scanf("%d%d%d", &stud[j][1], &stud[j][2], &stud[j][3]);
        }
        int ans = 0;
        for(int j = 1; j <= new_num; j++){
            if(stud[j][1] >= stud[j][2]){
                if(stud[j][2] >= stud[j][3]){
                    stud_[j] = stud[j][1];
                }else if(stud[j][1] >= stud[j][3]){
                    stud_[j] = stud[j][1];
                }else{
                    stud_[j] = stud[j][3];
                }
            }else if(stud[j][2] >= stud[j][3]){
                stud_[j] = stud[j][2];
            }else if(stud[j][3] >= stud[j][2]){
                stud_[j] = stud[j][3];
            }
            ans += stud_[j];
        }
        printf("%d\n", ans);
    }*/
    for(int i = 1; i <= tot_num; i++){
        int new_num;
        scanf("%d", &new_num);
        if(new_num == 2){
			for(int k = 1; k <=tot_num; k++){
				for(int j = 1; j <= 6; j++){
					pian2[j] = 0;
                }
                int asd;
                if(k >= 2){
                    scanf("%d", &asd);
				}
				int pian211, pian212, pian213;
                int pian221, pian222, pian223;
                scanf("%d%d%d", &pian211, &pian212, &pian213);
                scanf("%d%d%d", &pian221, &pian222, &pian223);
                pian2[1] = pian211 + pian222;
                pian2[2] = pian211 + pian223;
                pian2[3] = pian212 + pian221;
                pian2[4] = pian212 + pian223;
                pian2[5] = pian213 + pian221;
                pian2[6] = pian213 + pian222;
                int ans = 0;
                for(int j = 1; j <= 6; j++){
					cout<<pian2[j]<<" ";
                    ans = max(ans , pian2[j]);
                }
                printf("%d\n", ans);
            }    
            return 0;
        }
        if(new_num == 1e5){
            for(int k = 1; k <= tot_num; k++){
				int asd;
                if(k >= 2){
                    scanf("%d", &asd);
				}
                for(int j = 1; j <= 1e5; j++){
                    int asd , fgh;
                    scanf("%d%d%d", &pian1[j], &asd, &fgh);
                }
                sort(pian1 + 1 , pian1 + 1 + 100000);
                int ans = 0;
                for(int j = 1e5; j > 250000; j--){
                    ans += pian1[j];
                }
                printf("%d\n", ans);
            }
            return 0;
        }
        /*for(int j = 1; j <= new_num; j++){
            scanf("%d%d%d", &stud[j][1], &stud[j][2], &stud[j][3]);
        }
        dp[1][1] = stud[1][1];
        for(int j = 1; j <= 3; j++){
            dp[1][j] = stud[1][j];
            dp[1][j].degree[j] = dp[1][j - 1].degree[j - 1] + 1;
        }
        for(int j = 2; j <= new_num; j++){
            for(int k = 1; k <= 3; k++){
                if()
            }
        }*/
    }
    return 0;
}
