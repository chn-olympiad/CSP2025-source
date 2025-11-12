#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int s,b[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i=1;
    while(cin>>a[i])
    {
        if(a[i]=='0')
        {
            b[0]++;
        }
        if(a[i]=='1')
        {
            b[1]++;
        }
        if(a[i]=='2')
        {
            b[2]++;
        }
        if(a[i]=='3')
        {
            b[3]++;
        }
        if(a[i]=='4')
        {
            b[4]++;
        }
        if(a[i]=='5')
        {
            b[5]++;
        }
        if(a[i]=='6')
        {
            b[6]++;
        }
        if(a[i]=='7')
        {
            b[7]++;
        }
        if(a[i]=='8')
        {
            b[8]++;
        }
        if(a[i]=='9')
        {
            b[9]++;
        }
        i++;
    }
    for (int j=9;j>=0;j--)
    {
        int k=b[j];
        for(int t=1;t<=k;t++)
        {
            cout<<j;
        }
    }
    return 0;
}
