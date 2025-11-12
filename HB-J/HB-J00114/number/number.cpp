#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
    string n;
    int a,q,w,e,r,t,y,u,p,o,z;
    int count=0;
    cin>>n;
    for(int i=0;i<n.size();i++)
    {
        
        if(n[i]=='1')
        {
           q++;
        }
        if(n[i]=='2')
        {
           w++;
        }
        if(n[i]=='3')
        {
           e++;
        }
        if(n[i]=='4')
        {
           r++;
        }
        if(n[i]=='5')
        {
           t++;
        }
        if(n[i]=='6')
        {
           y++;
        }
        if(n[i]=='7')
        {
           u++;
        }
        if(n[i]=='8')
        {
           p++;
        }
        if(n[i]=='9')
        {
           o++;
        }
        if(n[i]=='0')
        {
           z++;
        }

    }
    count=q+w+e+r+t+y+u+p+o+z;
    for(int i=0;i<count;i++)
    {
        a*=10;
        if(o>0)
        {
            a+=9;
        }
        if(p>0)
        {
            a+=8;
        }
        if(u>0)
        {
            a+=7;
        }
        if(y>0)
        {
            a+=6;
        }
        if(t>0)
        {
            a+=5;
        }
        if(r>0)
        {
            a+=4;
        }
        if(e>0)
        {
            a+=3;
        }
        if(w>0)
        {
            a+=2;
        }
        if(q>0)
        {
            a+=1;
        }
    }
    cout<<a;
}