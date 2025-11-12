#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,i;
    cin >> n >> t >> i;
    for(int i=1;i<=0;i++)
    {
        if(n==2)
        {
            i+1=t;
            t=t+1;
        }
    }
    cout << n << i << t << endl;
    return 0;
}
