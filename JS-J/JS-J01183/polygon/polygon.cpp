#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    if(n < 3) cout << 0 << endl;
    if(n == 3){
        cin >> a >> b >> c;
        if(a+b > c && a+c > b && b+c > a) cout << 1 << endl;
        else cout << 0 << endl;
    }
}