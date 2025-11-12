#include<bits/stdc++.h>
using namespace std;
string aa;
long long n,i,j,k,a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>aa;
    for(i=0;i<aa.size();i++)
    {
        if(aa[i]>'9'||aa[i]<'0')
        {
            aa.erase(i,1);
            i--;
        }
    }
    for(i=0;i<aa.size();i++)
    {
        a[i+1]=int(aa[i]-48);
    }
    n=aa.size();
    sort(a+1,a+1+n);
    if(a[1]==0&&a[2]==0)
    {
        cout<<0;
        return 0;
    }
    for(i=n;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
