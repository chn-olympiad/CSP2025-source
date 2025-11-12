#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct sb{
    int a, b, c;
    int ap, bp, cp;
    int c12;
}s[N];
bool cmp(sb a, sb b){
    return a.c12 < b.c12;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        memset(s, 0, sizeof(s));
        int n;
        cin>>n;
        int jishu = n / 2;
        for(int i = 1;i <= n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            if(s[i].a > s[i].b && s[i].b > s[i].c){
                s[i].ap = 1, s[i].bp = 2, s[i].cp = 3;
            }else if(s[i].a > s[i].c && s[i].c > s[i].b){
                s[i].ap = 1, s[i].bp = 3, s[i].cp = 2;
            }else if(s[i].b > s[i].a && s[i].a > s[i].c){
                s[i].ap = 2, s[i].bp = 1, s[i].cp = 3;
            }else if(s[i].b > s[i].c && s[i].c > s[i].a){
                s[i].ap = 3, s[i].bp = 1, s[i].cp = 2;
            }else if(s[i].c > s[i].b && s[i].b > s[i].a){
                s[i].ap = 3, s[i].bp = 2, s[i].cp = 1;
            }else if(s[i].c > s[i].a && s[i].a > s[i].b){
                s[i].ap = 2, s[i].bp = 3, s[i].cp = 1;
            }
            else if(s[i].a == s[i].b && s[i].b == s[i].c){
                s[i].ap = 1, s[i].bp = 2, s[i].cp = 3;
            }
            else if(s[i].a == s[i].b && s[i].a > s[i].c){
                s[i].ap = 1, s[i].bp = 2, s[i].cp = 3;
            }else if(s[i].a == s[i].b && s[i].a < s[i].c){
                s[i].ap = 2, s[i].bp = 3, s[i].cp = 1;
            }else if(s[i].a == s[i].c && s[i].a > s[i].b){
                s[i].ap = 1, s[i].bp = 3, s[i].cp = 2;
            }else if(s[i].a == s[i].c && s[i].a < s[i].b){
                s[i].ap = 2, s[i].bp = 1, s[i].cp = 3;
            }else if(s[i].b == s[i].c && s[i].b > s[i].a){
                s[i].ap = 3, s[i].bp = 1, s[i].cp = 2;
            }else if(s[i].b == s[i].c && s[i].b < s[i].a){
                s[i].ap = 1, s[i].bp = 2, s[i].cp = 3;
            }
        }
        //for(int i = 1;i <= n;i++){
        //    cout<<s[i].ap<<" "<<s[i].bp<<" "<<s[i].cp<<endl;
        //}//tiaoshi1
        int aa = 0, bb = 0, cc = 0;
        int sum = 0;
        int fir, sec;
        for(int i = 1;i <= n;i++){
            if(s[i].ap == 1){
                aa++;
                sum += s[i].a;
                fir = s[i].a;
            }else if(s[i].ap == 2){
                sec = s[i].a;
            }
            if(s[i].bp == 1){
                bb++;
                sum += s[i].b;
                fir = s[i].b;
            }else if(s[i].bp == 2){
                sec = s[i].b;
            }
            if(s[i].cp == 1){
                cc++;
                sum += s[i].c;
                fir = s[i].c;
            }else if(s[i].cp == 2){
                sec = s[i].c;
            }
            s[i].c12 = fir - sec;
            //cout<<s[i].c12<<endl;//tiaoshi2
        }
        if(aa <= jishu && bb <= jishu && cc <= jishu){
            cout<<sum<<endl;
            //return 0;
        }else{
            sort(s + 1, s + n + 1, cmp);
            int hw = 0;
            int maxn = 0;
            if(aa > bb && aa > cc){
                maxn = aa;
                hw = 1;
            }else if(bb > aa && bb > cc){
                maxn = bb;
                hw = 2;
            }else if(cc > aa && cc > bb){
                maxn = cc;
                hw = 3;
            }
            //cout<<maxn<<endl;//tiaoshi3
            //cout<<sum<<endl;//tiaoshi4
            int www = maxn - jishu;
            for(int i = 1;;i++){
                if(hw == 1){
                    if(s[i].ap == 1){
                        sum -= s[i].c12;
                        www--;
                    }
                }else if(hw == 2){
                    if(s[i].bp == 1){
                        sum -= s[i].c12;
                        www--;
                    }
                }else if(hw == 3){
                    if(s[i].cp == 1){
                        sum -= s[i].c12;
                        www--;
                    }
                }
                if(www == 0){
                    break;
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
