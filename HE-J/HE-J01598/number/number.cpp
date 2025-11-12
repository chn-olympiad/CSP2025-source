#include<bits/stdc++.h>
using namespace std;

int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    char a[1000001];
    short b[1000001];
    int num=0;

    memset(a,'a',sizeof(a));
    memset(b,-1,sizeof(b));

    cin>>a;

    for(int i=0;i<1000001;i++)
    {
        if(a[i]>=48 && a[i]<=57)
        {
            b[num]=a[i]-'0';
            num++;
        }
    }

    int c[num];
    int x=0;    //C suo yin

    for(int i=0;i<num;i++)
    {
        int max=0;
        int y=-1;
        for(int j=0;j<num;j++)
        {
            if(b[j]>=max)
            {
                max=b[j];
                y=j;
            }
        }
        b[y]=-1;
        c[x]=max;
        x++;
    }
    for(int i=0;i<num;i++) cout<<c[i];
    return 0;
}
