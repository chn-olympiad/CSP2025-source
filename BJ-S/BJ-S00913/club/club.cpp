#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct stu{
    int a,b,c,fav,oths,idx,cha;
}s[N],tmp[N];
bool cmp(stu x,stu y){
    return x.cha > y.cha;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n,num1 = 0,num2 = 0,num3 = 0;
        int tot = 0,ans = 0,flag = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            if(s[i].a >= s[i].b && s[i].a >= s[i].c){
                s[i].fav = s[i].a;
                s[i].idx = 1;
                if(s[i].b > s[i].c) s[i].oths = s[i].b;
                else s[i].oths = s[i].c;
                num1++;
            }else if(s[i].b >= s[i].a && s[i].b >= s[i].c){
                s[i].fav = s[i].b;
                s[i].idx = 2;
                if(s[i].a > s[i].c) s[i].oths = s[i].a;
                else s[i].oths = s[i].c;
                num2++;
            }else{
                s[i].fav = s[i].c;
                s[i].idx = 3;
                if(s[i].b > s[i].a) s[i].oths = s[i].b;
                else s[i].oths = s[i].a;
                num3++;
            } 
        }
        if(num1 > n/2){
            flag = 1;
            for(int i = 1;i <= n;i++){
                if(s[i].idx == 1){
                    tmp[++tot].fav = s[i].fav;
                    tmp[tot].oths = s[i].oths;
                    tmp[tot].cha = tmp[tot].fav - tmp[tot].oths;
                }
            }
            sort(tmp+1,tmp+1+tot,cmp);
            for(int i = 1;i <= n/2;i++){
                ans += tmp[i].fav;
            }
            for(int i = n/2 + 1;i <= tot;i++){
                ans += tmp[i].oths;
            }
        }else if(num2 > n/2){
            flag = 2;
            for(int i = 1;i <= n;i++){
                if(s[i].idx == 2){
                    tmp[++tot].fav = s[i].fav;
                    tmp[tot].oths = s[i].oths;
                    tmp[tot].cha = tmp[tot].fav - tmp[tot].oths;
                }
            }
            sort(tmp+1,tmp+1+tot,cmp);
            for(int i = 1;i <= n/2;i++){
                ans += tmp[i].fav;
            }
            for(int i = n/2 + 1;i <= tot;i++){
                ans += tmp[i].oths;
            }
        }else if(num3 > n/2){
            flag = 3;
            for(int i = 1;i <= n;i++){
                if(s[i].idx == 3){
                    tmp[++tot].fav = s[i].fav;
                    tmp[tot].oths = s[i].oths;
                    tmp[tot].cha = tmp[tot].fav - tmp[tot].oths;
                }
            }
            sort(tmp+1,tmp+1+tot,cmp);
            for(int i = 1;i <= n/2;i++){
                ans += tmp[i].fav;
            }
            for(int i = n/2 + 1;i <= tot;i++){
                ans += tmp[i].oths;
            }
        }
        for(int i = 1;i <= n;i++){
            if(flag == 1 && s[i].idx == 1 || flag == 2 && s[i].idx == 2 || flag == 3 && s[i].idx == 3) continue;
            ans += s[i].fav;
        }
        cout << ans << '\n';
    }

    return 0;
}