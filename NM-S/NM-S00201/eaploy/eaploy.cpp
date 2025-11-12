#include <bits/stdc++.h>
using namespace std;
int mun=0,num=0,k=0;
int print()
{
    sum++;
}

void st()
{
    for(int i=0;i<501;i++)
    {
        for(int  j=0;j<n;j++)
        {
            
            if(s[j]=='0')
            {
                k++;
            }
            else num++;
            if(c[i]<k) k++;
            if(num>=m) print();
        }
    }
    
}
int main()
{
    freopen("eaploy.in","r",stdin);
    freopen("eaploy.out","w",stdout);
    int n,m;cin>>n>>m;int c[n];
    string;cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    st(c);
    for(int i=0;i<n;i++)
    {
        c[i],c[i+1]=c[i+1],c[i];
        st(c);
    }
    cout<<st(c);
    return 0;
}

