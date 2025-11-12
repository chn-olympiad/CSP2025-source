#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5+25;
struct node{
    int a,b,c,mn;
}s[N];

int n,T;
int cnta,cntb,cntc;
int ans;
void init(){
    memset(s,0,N);
    cnta = cntb = cntc = 0;
}
bool cmp2(node A,node B){
    return A.mn < B.mn;
}
main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cout << "";
    cin >> T;
    while(T--){

        cin >> n;
        ans = 0;
        init();
        for(int i = 1;i<=n;i++){
            cin >> s[i].a >> s[i].b >> s[i].c;
        }
        for(int i = 1;i<=n;i++){
            if(s[i].a >= s[i].b &&s[i].a >= s[i].c){
                cnta++;ans += s[i].a;
            }
            else if(s[i].b >= s[i].a &&s[i].b >= s[i].c){
                cntb++;ans += s[i].b;
            }
            else if(s[i].c >= s[i].a &&s[i].c >= s[i].b){
                cntc++;ans += s[i].c;
            }
        }   

        if(cnta <= n/2&&cntb <=n/2&&cntc<=n/2){cout << ans <<endl;continue;}
        if(cnta >= n/2)
            for(int i = 1;i<=n;i++)
                s[i].mn = min(s[i].a-s[i].b,s[i].a-s[i].c);
                
        else if(cntb >= n/2)
            for(int i = 1;i<=n;i++)
                s[i].mn = min(s[i].b-s[i].a,s[i].b-s[i].c);
        else
            for(int i = 1;i<=n;i++)
                s[i].mn = min(s[i].c-s[i].b,s[i].c-s[i].a);
        sort(s+1,s+n+1,cmp2);
        int v;
        if(cnta >= n/2)v = cnta - n/2;
        if(cntb >= n/2)v = cntb - n/2;
        if(cntc >= n/2)v = cntc - n/2;
        for(int i = 1;i<=n;i++){

            if(s[i].mn > 0){

                for(int j = 1;j<=v;i++,j++){
                    ans -= s[i].mn;
                }
                break;
            }
        }
        cout << ans << endl;
    }


    return 0;
}