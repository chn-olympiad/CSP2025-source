#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a;
    int g=0;
    char f;
    cin>>s;
    //cout<<s;
    int d=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            //cout<<s[i];
            a[d]=s[i];
            //cout<<a[d];
            d++;
        }
    }
    //cout<<d<<" ";
    if(d>=2)
    {
        for(int i=0; i<=d; i++)
        {
            for(int o=0; o<d; o++)
            {
                if(a[o]<a[o+1])
                {
                    f=a[o];
                    a[o]=a[o+1];
                    a[o+1]=f;
                }
                else if(a[o]==a[o+1])
                {
                    g=1;
                }
            }
        }
    }
    else
    {
        cout<<a[0];
        return 0;
    }
    for(int i=0; i<d+g; i++)
    {
        cout << a[i];
    }

    return 0;
}


