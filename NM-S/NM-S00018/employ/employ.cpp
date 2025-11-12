#include <bits/stdc++.h>
using namespace std;
struct ddd{
    int sh;
    int xiab;
};
int main()
{
    freopen("employ1.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,j;
    ddd a[500]={0};
    cin>>n>>m;
    string s;
    ddd d;
    cin>>s;
    int time=0;
    int ren=0;
    for(int i=0;i<n;i++)
    {
        cin>>j;
        a[i].sh=j;
        a[i].xiab=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int y=i+1;y<n;y++)
        {
            if(a[i].sh>=a[y].sh)
            {
                d=a[y];
                a[y]=a[i];
                a[i]=d;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[time]-'0'&&a[i].sh>=0)
        {
            ren++;
        }
        time++;
        for(int y=i;y<n;y++)
        {
            a[y].sh--;
        }
    }
    cout<<ren;
    return 0;
}
