#include<bits/stdc++.h>
using namespace std;
int p[1000005];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //48-57
    string a;
    
    
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(int(a[i])>=48&&int(a[i])<=57)
        {
            p[int(a[i])]++;
        }
    }
    for(int i=57;i>=48;i--)
    {
        for(int j=p[i];j>=1;j--)
        {
            cout<<i-48;
        }
    }
    
    return 0;
}

