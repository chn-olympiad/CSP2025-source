#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s,i;
    cin>>s>>i;
    for(int s;s>=1;s++)
    {
        if (s>=1)
        {
            s+=i;
        }
    }
    cout<<s;
    return 0;
}
