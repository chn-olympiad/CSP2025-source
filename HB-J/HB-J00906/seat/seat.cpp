#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a,b,i,k,c=0,t,z,d,x,ans1,ans2;
    string s,w;
    cin>>m>>n;
    b=m*n;
    for(a=0;a<b;a++) cin>>s[a];
    z=s[0];
    for(i=0;i<b;i++)
    {
        for(k=i;k<b;k++)
        {
            if(s[i]<s[k])
            {
                t=s[i];
                s[i]=s[k];
                s[k]=t;
            }
        }
        w[c]=s[i];
        c++;
    }
    for(x=0;x<b;x++)
    {
        if(w[x]==z)
        d=x+1;
    }
    if(d%n==0 && d/n%2==1)
    {
        ans1=d/n;
        ans2=m;
    }
    if(d%n==0 && d/n%2==0)
    {
        ans1=d/n;
        ans2=1;
    }
    if(d%n!=0 && d/n%2==0)
    {
        ans1=d/n+1;
        ans2=d%n;
    }
    if(d%n!=0 && d/n%2==1)
    {
        ans1=d/n+1;
        ans2=n-d%n;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}