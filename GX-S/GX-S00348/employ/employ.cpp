#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    int n;
    cin >>n;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        j*=i;
    }
    cout <<j;
    return 0;
}
