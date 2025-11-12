#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int h=1,l=1;
int num=0;
int main()
{
    cin>>n>>m;
    int x=n*m;
    for(int i=1;i<=x;i++)
    {
        cin>>a[i];
    }
    num=a[1];
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<x;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    int b;
    for(int i=1;i<=x;i++)
    {
        if(a[i]==num)
        {
            b=i;
            break;
        }
    }
    for(int i=1;i<b;i++)
    {
        if((h==n&&l%2==1)||(h==1&&l%2==0))
        {
            l++;
            continue;
        }
        if(l%2==0)
        {
            h--;
            continue;
        }
        else{
            h++;
            continue;
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
