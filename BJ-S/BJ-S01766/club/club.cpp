#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 100005;
int T,n,a[MAXN][3];
vector <int> val[3];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        val[0].clear();
        val[1].clear();
        val[2].clear();
        long long sum = 0;
        for(int i = 1;i <= n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            int mx = max(a[i][0],max(a[i][1],a[i][2]));
            sum += mx;
            if(a[i][0] == mx){
                val[0].push_back(a[i][0] - max(a[i][1],a[i][2]));
            }
            else if(a[i][1] == mx){
                val[1].push_back(a[i][1] - max(a[i][0],a[i][2]));
            }
            else{
                val[2].push_back(a[i][2] - max(a[i][0],a[i][1]));
            }
        }
        for(int i = 0;i < 3;i++){
            if(val[i].size() > (n >> 1)){
                sort(val[i].begin(),val[i].end());
                for(int j = 0;j < (int)val[i].size() - (n >> 1);j++){
                    sum -= val[i][j];
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
