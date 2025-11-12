#include <bits/stdc++.h>
using namespace std;
int shuju[110]={0};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n=0;
    int m=0;

    cin>>n>>m;

    for(int i=1;i<=(n*m);i++)
    {
        cin>>shuju[i];
    }

    int cj=shuju[1];
    int wz=0;
    sort(shuju+1,shuju+1+(n*m));

    for(int i=1;i<=(n*m);i++)
    {
        if(shuju[i]==cj)
        {
            wz=i;
        }
    }

    wz=(n*m)-wz+1;
    int xiaoshu=wz%n;
    int lie=((wz-xiaoshu)/n)+1;
    if(xiaoshu==0)
    {
        lie--;
    }
    if(wz<=n)
    {
        lie=1;
    }
    int hang=wz-((lie-1)*n);
    if(lie%2==0)
    {
        hang=n-hang+1;
    }


    /*int x=1;  //hang
    int y=1;  //lie

    bool b=true;  //true=danshu

    for(int i=1;i<=wz;i++)
    {
        if(x>n&&b)
        {
            x=n;
            y++;
            b=false;
        }
        if(x>0&&!b)
        {
            x=1;
            y++;
            b=true;
        }
        if(b)
        {
            x++;
        }
        else
        {
            x--;
        }
    }*/

    cout<<lie<<" "<<hang<<endl;
    return 0;
}
