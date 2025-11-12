#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct node{
    int a,b,c;
}s[N];
bool v;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int m = n/2;
        int ans = 0;
        int a1 = 0,b1 = 0,c1 = 0;
        int a2 = 0,b2 = 0,c2 = 0;
        for(int i = 1;i <= n;i++){
            cin >> s[i].a >> s[i].b >> s[i].c;
        }
        for(int i = 1;i <= n;i++){
            if(s[i].a>s[i].b&&s[i].a > s[i].c){
                if(a1 <= m){
                    a2 += s[i].a;
                }else if(s[i].b > s[i].c && b1 <= m){
                    b2 += s[i].b;
                } else if(s[i].c > s[i].b && c1 <= m){
                    c2 += s[i].c;
                }
            }else if(s[i].b>s[i].a&&s[i].b > s[i].c){
                if(b1 <= m){
                    b2 += s[i].b;
                }else if(s[i].a > s[i].c && a1 <= m){
                    a2 += s[i].a;
                } else if(s[i].c > s[i].a && c1 <= m){
                    c2 += s[i].c;
                }
            }else if(s[i].c>s[i].b&&s[i].c > s[i].a){
                if(c1 <= m){
                    c2 += s[i].c;
                }else if(s[i].a > s[i].b && a1 <= m){
                    a2 += s[i].a;
                } else if(s[i].b > s[i].a && b1 <= m){
                    b2 += s[i].b;
                }
            }
        }
        cout << a2+b2+c2 << '\n';
    }
    return 0;
}
