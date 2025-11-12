#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int zhao(int a[],int u,int len)
{
    for(int i=0;i<len;i++)
    {
        if(a[i]==u)
            return i;
    }
}
//int b[10000][10000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    int smp=a[0];
    sort(a,a+n*m,cmp);
    int num=0,ans=zhao(a,smp,m*n)+1;
    if(ans==1)
    {
        cout<<"1 1";
        return 0;
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(num==ans)
            {
                cout<<j+1<<" "<<i+1;

            }
            num++;
            //b[i][j]=a[num];

        }
        i++;
        for(int j=m-1;j>=0;j--)
        {
            if(num==ans)
            {
                cout<<j+1<<" "<<i+1;

            }
            num++;
            //b[i][j]=a[num];
        }
    }
/*
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }*/
    return 0;
}
