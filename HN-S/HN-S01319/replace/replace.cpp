#include<bits/stdc++.h>
using namespace std;
int n, q;
char s1[1010][2010], s2[1010][2010];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++){
        cin >> s1[i]+1 >> s2[i]+1;
    }
    while(q--){
        int ans = 0;
        char t1[2010], t2[2010];
        cin >> t1+1 >> t2+1;
        if(strlen(t1+1) != strlen(t2+1)){
            printf("0\n");
            continue;
        }
        for(int i = 1; i <= n; i++){
            int _ = strlen(t1+1)-strlen(s1[i]+1)+1;
            for(int j = 1; j <= _; j++){
                int flag = 1;
                for(int k = 1; k < j; k++){
                    if(t1[k] != t2[k]){
                        flag = 0;
                        break;
                    }
                }
                if(!flag) continue;
                for(int k = j; k <= j + strlen(s1[i]+1) - 1; k++){
                    if(t1[k] != s1[i][k-j+1] || t2[k] != s2[i][k-j+1]){
                        flag = 0;
                        break;
                    }
                }
                if(!flag) continue;
                for(int k = j+strlen(s1[i]+1); k <= strlen(t1+1); k++){
                    if(t1[k] != t2[k]){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    ans++;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
//我退役了，感谢这题让我结束 OI 生涯，愿天堂没有字符串--jrzhr