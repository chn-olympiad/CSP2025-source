#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s;
    cin>>s;
    for(int i=0;i<1000000;i++)
    {
       if(s==i)
            cout<<i<<endl;
    }


    return 0;
}
