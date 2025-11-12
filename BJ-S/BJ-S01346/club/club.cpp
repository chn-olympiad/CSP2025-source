#include<iostream>
#include <cmath>
using  namespace std;
void v(int y)
{
    int s[4][100010],a[6][100010];
    sizeof(s),sizeof(a);
    int z,q=0,w=0,e=0,c=0;
    cin>>z;
    for(int i=0;i<z;i++)
    {
        cin>>s[0][i]>>s[1][i]>>s[2][i];
        s[3][i]=max(s[0][i],max(s[1][i],s[2][i]));
        if(s[3][i]==s[0][i])a[0][q]=s[0][i],q++,a[3][q-1]=i;
        else if(s[3][i]==s[1][i])a[1][w]=s[1][i],w++,a[4][w-1]=i;
        else a[2][e]=s[2][i],e++,a[5][e-1]=i;
    }
    for(int i=max(q,max(w,e));i>0;i--)
    {
        for(int j=i-1;j>0;j--)
        {
            if(a[0][i]<a[0][j])swap(a[0][j],a[0][i]);
            if(a[1][i]<a[1][j])swap(a[1][j],a[1][i]);
            if(a[2][i]<a[2][i])swap(a[2][j],a[2][i]);
        }
    }
    if(q>z/2)
    {
        for(int i=0;i<q-z/2;i++)
        {
            int k=a[3][i];
            if(s[1][k]>s[2][k])
            {
                a[1][w]=s[1][k],w++,a[4][w-1]=k;
            }
            else
            {
                a[2][e]=s[2][k],e++,a[5][e-1]=k;
            }
        }
        for(int i=0;i<z/2;i++)c+=a[0][q-i];
    }
    else
    {
        for(int i=q;i>=0;i--)c+=a[0][i];
    }
    if(w>z/2)
    {
        for(int i=0;i<w-z/2;i++)
        {
            int k=a[4][i];
            if(s[0][k]>s[2][k]&&q-z/2>0)
            {
                c+=s[0][k],q++;
            }
            else
            {
                a[2][e]=s[2][k],e++,a[5][e-1]=k;
            }
        }
        for(int i=0;i<z/2;i++)c+=a[1][w-i];
    }
    else
    {
        for(int i=w;i>=0;i--)c+=a[1][i];
    }
    if(e>z/2)
    {
        for(int i=0;i<e-z/2;i++)
        {
            int k=a[5][i];
            if(s[0][k]>s[1][k]&&q-z/2>0)
            {
                c+=s[0][k],q++;
            }
            else
            {
                c+=s[1][k];
            }
        }
        for(int i=0;i<z/2;i++)c+=a[2][e-i];
    }
    else
    {
        for(int i=e+1;i>=0;i--)c+=a[2][i];
    }
    cout<<c<<"\n";
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int u;
    cin>>u;
    for(;u>0;u--)v(u);
    return 0;
}
