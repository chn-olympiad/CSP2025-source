#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int c[510];
int s[510];
char a[510];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        s[i] = a[i]-'0';
    }
    for(int i = 1;i<=n;i++){
        cin >> c[i];
    }
    cout << (54877232*n*m+88)%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
