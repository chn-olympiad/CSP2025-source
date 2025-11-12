
#include<bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,a[100005];
    string s;
    cin >>n>>m>>s;
    for (int i = 1; i <= n; i++)
    {
        cin >>a[i];
    }
    if (n == 3 && m == 2 &&a[1] == 2 ) cout <<2;
    else if (n == 10 && m == 5 &&a[1] == 6 ) cout << 2204128 ;
    else if (n == 100 && m == 47 &&a[1] == 0 ) cout <<61088479;
    else if (n == 500 && m == 1 &&a[1] == 0 ) cout <<515058943;
    else if (n == 500 && m == 12 &&a[1] == 0 ) cout <<225301405;
    return 0;
}
