#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    vector<int> a;
    int ma=-1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int s;
        cin>>s;
        sum+=s;
        if(s>ma)
        {
            ma=s;
        }
        a.push_back(s);
    }
    if(sum>2*ma)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
