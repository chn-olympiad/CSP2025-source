#include <bits/stdc++.h>
using namespace std;
int mun=0,k=0,num=0;string s;int n,m;
void print()
{
    mun++;
}
void st(int c[])
{
    for(int i=0;i<501;i++)
    {
        for(int j=0;j<n;j++)
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
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;int c[n];
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
		int t=c[i];
        c[i]=c[i+1];
        c[i+1]=t;
        st(c);
    }
    cout<<mun;
    return 0;
}
