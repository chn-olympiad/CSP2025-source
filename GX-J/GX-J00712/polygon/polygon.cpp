#include <iostream>

using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[5010]= {0},s;
    long long d;
    cin>>s;
    for(int i=0; i<s; i++)
    {
        cin>>a[i];
    }
    for(int i=3; i<=s; i++)
    {
        for(int o=1; o<s; o++)
        {
            if(a[o]+a[o+1]>a[o+2]&&a[o+1]+a[o+2]>a[o]&&a[o]+a[o+2]>a[o+1])
            {
                s+1;
            }
        }
    }
    cout << s;
    return 0;
}
