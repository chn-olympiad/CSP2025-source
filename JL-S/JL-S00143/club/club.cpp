#include <bits/stdc++.h>
using namespace std;
int t,n,ans,man,a,b,c;
int main(){
    freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);
    scanf ("%d",&t);
    int sum = 0;
    for (int i = 1;i <= t;i++){
        scanf ("%d",&n);
        for (int j = 1;j <= n;j++){
            ans = n / 2;
            scanf ("%d%d%d",&a,&b,&c);
            if (a > b&&a > c)
                    man += a;
            else if (b > a&&b > c)
                man += b;
            else if (c > a&&c > b)
                man += c;
        }
    }
    cout << man << endl;
    return 0;
}
