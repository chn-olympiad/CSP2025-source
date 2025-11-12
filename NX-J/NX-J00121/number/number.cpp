#include<bits/stdc++.h>
using namespace std;
string b[1000001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int c=0;
    cin>>a;
    for(int i=0;c>-1;i++)
    {
        if(a[i]=1 || a[i]=2 || a[i]=3 || a[i]=4 || a[i]=5 || a[i]=6 || a[i]=7 || a[i]=8 || a[i]=9 || a[i]=0)
        {
            b[c]=a[i];
            c++;
        }
        if(a[i]=" ")
        {
            c=-1;
        }
    }

    for(long long i=1;i<=1000001;i++)
    {
        int max=b[0];
        for(long long j=1;j<=1000001;j++)
        {
            if(b[j]>max)
            {
                int g=max;
                max=b[j];
                b[j]=g;
            }
        }
        cout<<max;
    }
    return 0;
}
