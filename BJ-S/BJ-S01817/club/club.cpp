#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    long long a,b,c;
}p[100005];
bool cmp(node a,node b){
    if(2 * max({a.a,a.b,a.c}) + min({a.a,a.b,a.c}) - (a.a + a.b + a.c) != 2 * max({b.a,b.b,b.c}) + min({b.a,b.b,b.c}) - (b.a + b.b + b.c)){
        return (2 * max({a.a,a.b,a.c}) + min({a.a,a.b,a.c}) - (a.a + a.b + a.c) > 2 * max({b.a,b.b,b.c}) + min({b.a,b.b,b.c}) - (b.a + b.b + b.c));
    }
    else if(max({a.a,a.b,a.c}) != max({b.a,b.b,b.c})){
        return max({a.a,a.b,a.c}) > max({b.a,b.b,b.c});
    }
    else if((a.a + a.b + a.c) - max({a.a,a.b,a.c}) - min({a.a,a.b,a.c}) != (b.a + b.b + b.c) - max({b.a,b.b,b.c}) - min({b.a,b.b,b.c})){
        return (a.a + a.b + a.c) - max({a.a,a.b,a.c}) - min({a.a,a.b,a.c}) > (b.a + b.b + b.c) - max({b.a,b.b,b.c}) - min({b.a,b.b,b.c});
    }
    else{
        return min({a.a,a.b,a.c}) > min({b.a,b.b,b.c});
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        memset(p,0,sizeof(p));
        cin >> n;
        for(int i = 1;i <= n;i++)cin >> p[i].a >> p[i].b >> p[i].c;
        sort(p + 1,p + n + 1,cmp);
        long long ans = 0;
        int acnt = 0,bcnt = 0,ccnt = 0;
        for(int i = 1;i <= n;i++){
            if(p[i].a > p[i].b && p[i].a > p[i].c){
                if(acnt < (n / 2)){
                    acnt++;
                    ans += p[i].a;
                }
                else{
                    if(p[i].b > p[i].c && bcnt < (n / 2)){
                        bcnt++;
                        ans += p[i].b;
                    }
                    else{
                        ccnt++;
                        ans += p[i].c;
                    }
                }
            }
            else if(p[i].b > p[i].a && p[i].b > p[i].c){
                if(bcnt < (n / 2)){
                    bcnt++;
                    ans += p[i].b;
                }
                else{
                    if(p[i].a > p[i].c && acnt <= (n / 2)){
                        acnt++;
                        ans += p[i].a;
                    }
                    else{
                        ccnt++;
                        ans += p[i].c;
                    }
                }
            }
            else if(p[i].c > p[i].a && p[i].c > p[i].b){
                if(ccnt < (n / 2)){
                    ccnt++;
                    ans += p[i].c;
                }
                else{
                    if(p[i].a > p[i].b && acnt <= (n / 2)){
                        acnt++;
                        ans += p[i].a;
                    }
                    else{
                        bcnt++;
                        ans += p[i].b;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
