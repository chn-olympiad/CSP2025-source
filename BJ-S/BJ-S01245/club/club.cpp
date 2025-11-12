#include <bits/stdc++.h>

using namespace std;
long long n;
long long a[100005][3];
long long b[100005];
long long s[100005];
long long o[100005],tot;
long long ma1,ma2,ma3;
long long ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long T;
    cin >> T;
    while(T--){
        cin >> n;
        ma1 = 0;
        ma2 = 0;
        ma3 = 0;
        tot = 0;
        ans = 0;
        for(long long i = 1;i <= n;i++){
            cin >> a[i][0] >>a[i][1] >> a[i][2];
            if(a[i][0] >= a[i][1] and a[i][0] >= a[i][2]){
                ma1++;
                b[i] = min(a[i][0]-a[i][1],a[i][0] - a[i][2]);
                s[i] = 1;
                ans += a[i][0];
            }else if(a[i][1] >= a[i][2]){
                ma2++;
                b[i] = min(a[i][1]-a[i][0],a[i][1] - a[i][2]);
                s[i] = 2;
                ans += a[i][1];
            }else{
                ma3++;
                b[i] = min(a[i][2]-a[i][0],a[i][2] - a[i][1]);
                s[i] = 3;
                ans += a[i][2];
            }
            //cout << ' ' << b[i] << endl;
        }
        if(ma1 > n/2){
            for(long long i =1;i<= n;i++){
                if(s[i] == 1){
                    o[++tot] = b[i];
                }
            }
            sort(o+1,o+1+tot);
            for(long long i = 1;i <= ma1 - n/2;i++){
                ans -= o[i];
            }
        }else if(ma2 > n/2){
            for(long long i =1;i<= n;i++){
                if(s[i] == 2){
                    o[++tot] = b[i];
                    //cout << i;
                }
            }
            sort(o+1,o+1+tot);
            for(long long i = 1;i <= ma2 - n/2;i++){
                ans -= o[i];
                //cout<<ans;
            }
        }else if(ma3 > n/2){
            for(long long i =1;i<= n;i++){
                if(s[i] == 3){
                    o[++tot] = b[i];
                }
            }
            sort(o+1,o+1+tot);
            for(long long i = 1;i <= ma3 - n/2;i++){
                ans -= o[i];
            }
        }
        cout << ans << endl;
    }


    return 0;
}
