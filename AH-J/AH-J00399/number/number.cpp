#include<bits/stdc++.h>
using namespace std;
string a;
int m,b[1000005];
int main(void)
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a;
    int n=a.length();
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            m++;
            b[m]=a[i]-'0';
        }
    }
    sort(b,b+1+m);
    for(int i=m;i>0;i--)cout<<b[i];
    return 0;
}
