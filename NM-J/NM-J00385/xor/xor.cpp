#include <bits/stdc++.h>
using namespace std;
long long n,m,s,d,f,t,k,a[100000];
int ob(int x)
{
    int t[10000],d,l;
    for(d=0;d<10000;d++)
     t[d]=0;
    for(d=0;x!=0;x=x/2,d++)
     t[d]=x%2;
    for(l=0,x=d-1;x>=0;x--)
     l=l*10+t[x];
    return l;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int m1,m2,m3;
    cin>>n>>k;
    for(s=0;s<n;s++)
    {
        cin>>a[s];
    }
    for(s=0;s<n-1;s++)
    {
        for(d=s;d<n-1;d++)
        {
            for(m=s,f=0;m<=d;m++)
            {
                m1=m1+a[m];
                m2=ob(m1);
                m3=ob(a[m+1]);
                if(a[m]==k)
                 t++;
            }
        }
    }
    cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
