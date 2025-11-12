#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b=a.size();
    string d;
    for (int i=0;i<a.size();i++)
    {
        if(a[i]<9&&a[i]>=0)
        {
            d[i]=a[i];
        }
    }
    for(int j=0;j<d.size();j++)
    {
        for(int i=0;i<d.size()-1;i++)
        {
            if(d[i]<d[i+1])
            {
                swap(d[i],d[i+1]);
            }
        }
    }
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i];
    }
    return 0;
}