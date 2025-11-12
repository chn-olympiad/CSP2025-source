#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define inf 0x3f3f3f3f
struct Students{
    int id;
    int a,b,c;
}stu[maxn];
int t,n;
int chx,chy;
bool cmp(Students x,Students y){
    int tmp1[3] = {x.a,x.b,x.c};
    int tmp2[3] = {y.a,y.b,y.c};
    sort(tmp1,tmp1 + 3);
    sort(tmp2,tmp2 + 3);
    chx = tmp1[2] - tmp1[1];
    chy = tmp2[2] - tmp2[1];
    return chx > chy;
}
int cnta,cntb,cntc;
long long ans;
int main(){
    //freopen("club5.in","r",stdin);
    //freopen("club5.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0,cnta = cntb = cntc = 0;
        for(int i = 1;i <= n;i++){
            cin >> stu[i].a >> stu[i].b >> stu[i].c;
            stu[i].id = i;
        }
        sort(stu + 1,stu + n + 1,cmp);
        for(int i = 1;i <= n;i++){
            Students u = stu[i];
            if(u.a > u.b && u.a > u.c){
                if(cnta < n / 2){
                    cnta++;
                    ans += u.a;
                }
            }
            else if(u.b > u.c){
                if(cntb < n / 2){
                    cntb++;
                    ans += u.b;
                }
            }
            else{
                if(cntc < n / 2){
                    cntc++;
                    ans += u.c;
                }
            }
            if(cnta == n / 2){
                for(int j = i + 1;j <= n;j++){
                    stu[j].a = -inf;
                }
                sort(stu + i + 1,stu + n + 1,cmp);
            }
            if(cntb == n / 2){
                for(int j = i + 1;j <= n;j++){
                    stu[j].b = -inf;
                }
                sort(stu + i + 1,stu + n + 1,cmp);
            }
            if(cntc == n / 2){
                for(int j = i + 1;j <= n;j++){
                    stu[j].c = -inf;
                }
                sort(stu + i + 1,stu + n + 1,cmp);
            }
            //cout << ans << " ";
        }
        //cout << endl;
        cout << ans << endl;
    }
    return 0;
}
