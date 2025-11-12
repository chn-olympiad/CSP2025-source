#include<bits/stdc++.h>
using namespace std;
struct sss
{
    int i;
    int a;
};
bool ccc(sss a,sss b)
{
    if(a.a<b.a)
    return 1;
    else
    return 0;
}
int main()
{

    int m,n;
    printf("%d %d",m,n);
    int s=m*n;
     sss v[110];
    for(int i=0;i<s;i++)
    {
        cin>>v[i].a;
        v[i].i=i;
    }
    sort(v,v+100,ccc);
    int cr;
    for(int i=0;i<s;i++)
    {
        if(v[i].i==1)
        cr=i;
    }
    int c=1,r;
    while(cr>=m)
    {
        cr-m;
        c++;
    }
    if(c%2==0)
        r=m-cr;
    else
        r=cr;

    cout<<c<<' '<<r;
    return 0;
}
