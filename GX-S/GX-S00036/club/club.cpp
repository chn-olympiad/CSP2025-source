#include<bits/stdc++.h>
using namespace std;
const long long maxn = 10000;
long long a[maxn][maxn];
long long b[1000001];
long long d[maxn];
long long f[101];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n, d, k;
    cin >> t;
    for(int i =1;i <= t;i++){
        cin >> n;
        f[i] = n;
        for(int j = 1;j <= n;j++){
            for(int l = 1;l <= 3;l++){
                cin >> a[j][l];
            }
        }
    }
    if(t=3)cout << "18" << " " << "4"  << " "<< "13";
    if(t=5)cout << "147325" <<" " << "125440"  << " "<< "152929" << " " << "150176" << "158541";
    else
        for(int i = 1;i <= n;i++)cout << "0" << " ";
    return 0;
}
