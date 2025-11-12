#include<bits/stdc++.h>
using namespace std;
string s,p;
int l[10];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);

    cin>>s;
    int j=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            int f=s[i];
            l[f]++;
            cout<<f;
        }

    }
    for(int i=9;i>=0;i--)
    {
        if(l[i]>=1)
        {
            for(int y=1;y<=l[i];y++)
            {
                p[j]=i;
                j++;
            }

        }

    }
    for(int i=0;i<=j-1;i++)
    {

        cout<<p[i];
    }
    return 0;
}
