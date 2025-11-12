#include <bits/stdc++.h>
using namespace std;
int main ()
 {
int t,n,a,b,c,d;
  cin >> t >> n ;
  if (n%2==1) cout << " ";
   else cin >> a >> b >> c;
   if (a>=b&&a>=c) d=a;
     else
    {
     if (b>=a&&b>c) d=b;
     else d=c;
    }
    cout << d;
    return 0;
}
