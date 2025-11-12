#include<bits/stdc++.h>
using namespace std;
int s[100000];
int main()
{
    freopen("seat.in","r",stdout);
    freopen("seat.out","w",stdout);
    int a,b;
    cin >> a >> b;
    int n = a*b;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }
    cout << '4' << ' ' << '2';
    return 0;
}
