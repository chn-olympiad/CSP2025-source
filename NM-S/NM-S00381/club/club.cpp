#include<bits/stdc++.h>
const int N = 1e5+5;
using namespace std;
struct pi{
    int maf,mas,dmaf,dmas, jc;
}pp[N];
int n, a1, a2, a3;
int t;
bool cmd(pi a, pi b){
    if(a.jc!=b.jc) return a.jc>b.jc;
    else if(a.mas != b.mas) return a.mas>b.mas;
    else return a.dmas > b.dmas;
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int top=n/2;
        for(int i = 1; i <= n; i++){
            scanf("%d %d %d", &a1, &a2, &a3);
            if(a1>=a2&&a1>=a3){
                pp[i].mas = a1;
                pp[i].maf = 1;
                if(a2>=a3) pp[i].dmas = a2, pp[i].dmaf = 2;
                else pp[i].dmas = a3, pp[i].dmaf = 3;
            }else if(a2>=a1&&a2>=a3){
                pp[i].mas = a2;
                pp[i].maf = 2;
                if(a1>=a3) pp[i].dmas = a1, pp[i].dmaf = 1;
                else pp[i].dmas = a3, pp[i].dmaf = 3;
            }else if(a3>=a2&&a3>=a1){
                pp[i].mas = a3;
                pp[i].maf = 3;
                if(a2>=a1) pp[i].dmas = a2, pp[i].dmaf = 2;
                else pp[i].dmas = a1, pp[i].dmaf = 1;
            }
            pp[i].jc = pp[i].mas-pp[i].dmas;
        }
        sort(pp+1, pp+1+n, cmd);
        int cnt[] = {0,0,0,0}, ans=0;
        for(int i = 1; i <= n; i++){
            if(cnt[pp[i].maf]<top) {ans+=pp[i].mas; cnt[pp[i].maf]++;}
            else {ans+=pp[i].dmas; cnt[pp[i].dmaf]++;}
        }
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
