#include<bits/stdc++.h>
using namespace std;
int n,m,xm,hao;
int a[205];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int nm=n*m;
    for(int i=1;i<=nm;i++)
    {
        cin>>a[i];
    }
    xm=a[1];
    sort(a+1,a+1+nm,cmp);
    for(int i=1;i<=nm;i++)
    {
        //cout <<a[i];
        if(a[i]==xm)
        {
            hao=i;
            break;
        }
    }
    if(hao<=n)
    {
        cout <<1<<" "<<hao;
        return 0;
    }
    else
    {
        int chu=hao/n;
        int yu=hao%n;
        if(chu%2==0)
        {
            if(yu==0)
            {
                cout <<chu<<" "<<1;
                return 0;
            }
            cout <<chu+1<<" "<<yu;
            return 0;
        }
        else if(chu%2!=0)
        {
            if(yu==0)
            {
                cout <<chu<<" "<<n;
                return 0;
            }
            cout <<chu+1<<" "<<n-yu+1;
            return 0;
        }
    }
    return 0;
}
