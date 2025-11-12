#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e5+5;
struct Memeber {
    int id;
    int x,y,z;
} club[maxn];

vector<int> aaa;
int a[maxn],b[maxn];

bool cmp(const int &a, const int &b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T,n,mx,ans;
    cin >> T;

    while(T--)
    {
        cin >> n;
        mx = n / 2;

        bool z2=true,z3=true;

        for(int i = 1; i <= n; i++){
            cin >> club[i].x >> club[i].y >> club[i].z;
            club[i].id = i;
            if(club[i].y != 0) z2=false;
            if(club[i].z != 0) z3=false;
        }

        if(n == 2){
            ans = 0;
            vector<int> an;
            an.push_back( club[1].x + club[2].y);
            an.push_back( club[1].x + club[2].z);
            an.push_back( club[1].y + club[2].x);
            an.push_back( club[1].y + club[2].z);
            an.push_back( club[1].z + club[2].x);
            an.push_back( club[1].z + club[2].y);
            for(int i = 0; i < 6; i++){
                if(an[i] > ans) ans = an[i];
            }

            cout << ans << endl;

            continue;
        }

        if(z2 == true && z3 == true){
            ans = 0;
            for(int i = 1; i <= n; i++){
                a[i] = club[i].x;
            }

            sort(a+1,a+1+n,cmp);

            for(int i = 1; i <= n/2; i++){
                ans += a[i];
            }

            cout << ans << endl;
            continue;
        }

        if(z3== true){
            ans = 0;
            for(int i = 1; i <= n; i++){
                a[i] = club[i].x;
                b[i] = club[i].y;
            }

            sort(a+1,a+1+n,cmp);
            sort(b+1,b+1+n,cmp);

            for(int i = 1; i <= n/2; i++){
                ans += a[i];
            }

            cout << ans << endl;
            continue;
        }

/*
        for(int i = 1; i <= n; i++){

            dp[i] = max( max(club[i].x ,club[i].y) ,club[i].z) + dp[i-1];

        }

        cout << dp[n] << endl;


        ans = 0;
        for(int i = 1; i<= n ; i++){
            for(int j = i+1; j <= n; j++){
                aaa.push_back( club[i].x + club[j].y);
                aaa.push_back( club[i].x + club[j].z);
                aaa.push_back( club[i].y + club[j].x);
                aaa.push_back( club[i].y + club[j].z);
                aaa.push_back( club[i].z + club[j].x);
                aaa.push_back( club[i].z + club[j].y);
            }
        }
*/

    }

    return 0;
}
