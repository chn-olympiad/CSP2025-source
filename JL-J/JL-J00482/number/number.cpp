#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s,sum=0;
    cin>>s;
    if(s>10&&s<100)
    {
        sum=s-(s/10)*10;
        sum*=10;
        cout<<sum+(s/10);
    }
    else
        cout<<s;
    if(s>100)
    {
        sum=s-(s/100)*10;
        sum*=10;
        cout<<sum+(s/10);
    }
    return 0;
}
