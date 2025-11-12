#include"bits/stdc++.h"
using namespace std;
const int N=1e6+10;
char p[N]={0};
string a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int l=0;
    for(int i=0;i<sizeof(a);i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            p[l]=a[i];
            l++;
        }
    }
    sort(p,p+l);
    for(int i=l;i>=0;i--)
    {
        cout<<p[i];
    }
    return 0;
}
