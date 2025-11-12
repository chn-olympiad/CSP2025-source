#include <iostream>

using namespace std;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n ,m ,k;
    int u, v, m;
    long long sum;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> m;
        sum += m;
    }
    cout << m << endl;
    return 0;
}
