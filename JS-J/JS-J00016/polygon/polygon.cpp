#include <bits/stdc++.h>
using namespace std;
int a[5050],n;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int maxx = -1;
    long long cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cnt += a[i];
        maxx = max(maxx,a[i]);
    }if(cnt <= 2 * maxx){
        cout << 0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
