#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,mi = 10000,ma = 0,c,r;
    int b[25][25] = { };
    cin>>n>>m;
    int a[25] = { };
    for(int i=1;i <= n * m;i ++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i <= n * m;i ++){
        for(int j=1;j <= n * m;j ++){
            if(a[i] == a[1]){
                c = 2 * n - i;
                r = 2 * n - i;
            }
        }
    }
    cout<<c<<' '<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
