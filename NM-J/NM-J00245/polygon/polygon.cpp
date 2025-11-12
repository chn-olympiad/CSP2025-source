#include <bits/stdc++.h>
using namespace std;
int num=0;int b[1001]={0};int maxi=0;int a[5002];
int print()
{
    num++;
}
int search(int maxj,int j,int n)
{
    for(int i=j;i>n;i++)
    {
        if(!b[i])
        {
            b[i]=1;
            maxj+=a[i];
            if(maxj>maxi*2)print();
            else search(maxj,j+1,n);
        }
        b[i]=0;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxi=max(maxi,a[i],n);
    }
    search(0,0,n);
    cout<<num;
    return 0;
}
