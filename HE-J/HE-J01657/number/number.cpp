#include<bits/stdc++.h>
using namespace std;
string s,x;
long long a,b[1001],c=0,k,l=0;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;

    a=s.size();

    while(a!=-1)
    {

        if(s[a]<=57&&s[a]>=48)
        {
            x=x+s[a];
            b[c]=int(s[a])-48;
            c++;
        }
    a=a-1;
    }
    for(int i=0;i<=c-2;i++)
    {

        for(int o=0;o<=c-2-i;o++)
        {
            if(b[o]<=b[o+1])
            {
                k=b[o+1];
                b[o+1]=b[o];
                b[o]=k;

            }

        }
    }

    k=0;
    for(int i=0;i<=c-1;i++)
    {
        k=b[i];
        for(int o=0;o<=c-2-i;o++)
        {

            k=10*k;
        }
        l=l+k;
    }
    cout<<l;


    return 0;
}
