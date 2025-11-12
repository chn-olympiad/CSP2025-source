#include<bits/stdc++.h>
using namespace std;
long long z[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')
        z[0]++;
        else if(a[i]=='1')
        z[1]++;
        else if(a[i]=='2')
        z[2]++;
        else if(a[i]=='3')
        z[3]++;
        else if(a[i]=='4')
        z[4]++;
        else if(a[i]=='5')
        z[5]++;
        else if(a[i]=='6')
        z[6]++;
        else if(a[i]=='7')
        z[7]++;
        else if(a[i]=='8')
        z[8]++;
        else if(a[i]=='9')
        z[9]++;
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=z[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
