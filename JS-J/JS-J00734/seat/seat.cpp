#include<bits/stdc++.h>
using namespace std;
int moder[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a;
    int n,m;
    cin>>n>>m;
    int na=n*m;
    for(int i=1;i<=na;i++)
    {
        cin>>moder[i];
    }
    a=moder[1];
    sort(moder+1,moder+na+1);
    int w=na/2;
    for(int i=1;i<=w;i++)
    {
        swap(moder[i],moder[na-i+1]);
    }
    int ax=1,ay=1;
    for(int i=1;i<=na;i++)
    {
        if(moder[i]==a)
        {
            cout<<ay<<" "<<ax;
            break;
        }
        if(ay%2==1)
        {
            if(ax==n)
            {
                ay++;
            }
            else
            {
                ax++;
            }
        }
        else
        {
            if(ax==1)
            {
                ay++;
            }
            else
            {
                ax--;
            }
        }

    }
    return 0;
}
