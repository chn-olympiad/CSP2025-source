#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char n,m=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=a[i-1] || a[i]>=a[i-1])
        {

        }
        else if(a[i+1]>=a[i-1] || a[i+1]>=a[i])
        {

        }
        else if(a[i-1]>=a[i+1] || a[i-1]>=a[i])
        {

        }
    }
    return 0;
    //小R not木;
}
