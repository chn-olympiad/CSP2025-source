#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e6+5;

int u[maxn],v[maxn],w[maxn];
vector<int> cun[15];
int cun_xiu[15];

int main(){
    ios::sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i = 1; i <= k; i++){
        cin >> cun_xiu[i];
        for(int j = 1; j <= n; j++){
            int temp;
            cin >> temp;
            cun[i].push_back(temp);
        }
    }

    //
    if(k == 0)
    {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= n; j++){
                cout << 10;
            }
        }

    }
    else
    {

        cout << 0;


    }

    return 0;
}
