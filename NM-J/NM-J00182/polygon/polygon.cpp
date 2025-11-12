include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=3;i++)
    {
        if(a<b)
        {
            int e=a;
            a=b;
            b=e;
        }
        if(a<c)
        {
            int f=a;
            a=c;
            c=f;
        }
        if(b>c)
        {
            int g=c;
            c=b;
            b=g;
        }
    }
    if(b+c>a)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0";
    }
    return 0;
}
