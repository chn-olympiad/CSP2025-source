#include<bits/stdc++.h>
using namespace std;
int sum[1050];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n=0;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>=48&&a[i]<=57)
        {
            sum[++n]=a[i]-49;
        }
    }
    sort(sum+1,sum+n+1);
    for(int i=n;i>=1;i--)
    {
        cout<<sum[i]+1;
    }
    return 0;
}
