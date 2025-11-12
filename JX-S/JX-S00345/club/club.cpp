#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int high[4];
vector<int > last[4];
int ans, H, n;
void init(){
    cin>> n;
    high[1] = high[2] = high[3] = 0;
    ans = H = 0;
    for(int i=1; i<=3; i++) last[i].clear();
    for(int i=1; i<=n; i++){
        int a, b, c, maxx, num, k;    cin>> a>> b>> c;
        if(a > max(b,c)) {maxx = 1;num = a - max(b,c);k = a;}
        else if(b > c)   {maxx = 2;num = b - max(a,c);k = b;}
        else             {maxx = 3;num = c - max(b,a);k = c;}

        high[maxx] ++;
        last[maxx].push_back(num);
        ans += k;
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;cin>> T;
    while(T--){
        init();
        H = max(high[1], max(high[2], high[3]));
        if(high[1] > max(high[2], high[3])) H = 1;
        if(high[2] > max(high[1], high[3])) H = 2;
        if(high[3] > max(high[1], high[2])) H = 3;

        sort(last[H].begin(), last[H].end());

        for(int i=high[H]-n/2, j=0; i; i--, j++){
            ans -= last[H][j];
        }
        cout<<ans<<endl;

    }


    return 0;
}
