#include <bits/stdc++.h>
using namespace std;
//目前得分：[0,40]+16+[0,5]+25 = [41,86]
int f,uc,k,cc,f;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    long long price = 0;
    cin >> n >> m >> k;
    for (int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        price += c;
    }
    cout << price << endl;
    return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/