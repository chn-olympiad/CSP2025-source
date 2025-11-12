#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct node
{
    int g;
    int n;
};
node nnn[10005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int s;
    int sss;
    int nn,mm;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>nnn[i].g;
    }
    nnn[1].n=114;
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m-1;j++)
        {
            if(nnn[j].g<=nnn[j+1].g)
            {
                node c=nnn[j];
                nnn[j]=nnn[j+1];
                nnn[j+1]=c;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(nnn[i].n==114)
        {
            s=i;
            break;
        }
    }
    int seat=s%(2*n);
    if(seat%(2*n)<=n&&seat%(2*n)!=0)
    {
        nn=seat%(2*n);
    }
    else if(seat%(2*n)==0)
    {
        nn=1;
    }
    else
    {
        nn=2*n-seat%(2*n)+1;
    }
    mm=ceil(s/(n*1.0));
    cout<<mm<<" "<<nn;
    return 0;
}
