#include <iostream>
#include <cstdio>
using namespace std;
int n,t,i,a1,a2,a3;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);


    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a1>>a2>>a3;
        cout<<a1+a2+a3<<endl;

    }

    return 0;

}
