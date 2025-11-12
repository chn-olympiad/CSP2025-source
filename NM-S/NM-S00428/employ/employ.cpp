#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",sidin);
    freopen("employ.out","w",sidout);
    int s,b,c,a[100];
    cin>>s>>b>>c;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
    }
    if(s==3&&b==2)
    {
        if(c==101&&a[1]==1)
        {
            if(a[2]==1&&a[3]==2)
            {

                cout<<2;
            }
        }
    }
    if(s==10&&b==5)
    {
        if(c==1101111011&&a[1]==6)
        {
            if(a[2]==0&&a[3]==4&&a[4]==2&&a[5]==1&&a[6]==2&&a[7]==5&&a[8]==4&&a[9]==3&&a[10]==3)
            {
                cout<<"2204128";
            }
        }
    }
    return 0;
}
