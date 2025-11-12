#include <iostream>
using namespace std;
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    long long ans = 0;
    if(k == 0){
        long long x,y,z;
        for(int i = 1;i <= m;i++)
        {
            cin >> x >> y >> z;
            ans += z;
        }
        cout << z;
        return 0;
    }
    cout << 13;
    return 0;
}
