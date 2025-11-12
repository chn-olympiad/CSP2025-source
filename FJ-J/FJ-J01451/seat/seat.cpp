#include<bits/stdc++.h>
using namespace std;
int guys[101];
int cmp(int a,int b)
{
    // Fucking Compare Logic
    return a>b;
}
int main()
{
    // Fuck this CODE
    // Fuck SB Freopen
    // Fuck Tester
    // Don't FOR DAMN REMOVE THIS
    // Fuck TLE  Damn RE  Shit WA  Wish AC
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    freopen("WARN.ERR","w",stderr);
    // N lines M per line
    int n,m,tempshit;
    cin>>n>>m;
    tempshit=m*n;
    for(int i=0;i<=tempshit;i++)
    {
        cin>>guys[i];
    }
    tempshit=guys[0];
    sort(guys,guys+n*m,cmp);
    for(int i=0;i<n*m;i++)
    {
        if(guys[i]==tempshit)
        {
            tempshit=i+1;
            break;
        }
    }
    int tempfuck=0;
    if(tempshit%n!=0)
    {
        tempfuck=tempshit%m;
        tempshit=tempshit/m+1;
    }
    else tempshit=tempshit/m;
    if(tempshit%2)
    {
        if(tempfuck==0) cout<<tempshit<<' '<<n;
        else cout<<tempshit<<' '<<tempfuck;
    }
    else
    {
        if(tempfuck==0) cout<<tempshit<<' '<<1;
        else cout<<tempshit<<' '<<n-tempfuck+1;
    }
    return 0;
}
