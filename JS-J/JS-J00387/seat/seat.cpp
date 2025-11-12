#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],b[101],p,x,y,k=1;
bool f=true;
int pai(int x)
{
    for(int i=1;i<x;i++)
    {
        for(int k=i+1;k<=x;k++)
        {
            if(b[k]>b[i])
            {
                swap(b[k],b[i]);
            }
        }
    }
    return 0;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
    {
        cin>>b[i];
    }
    p=b[1];
    pai(m*n);
    for(int i=1;i<=m*n;i++)
    {
        if(b[i]==p)
        {
            p=i;
        }
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            a[i][j]=b[k];
            if(k==p)
            {
                x=i;
                y=j;
                f=false;
                break;
            }
            k++;
        }
        if(f==false)
        {
            break;
        }
    }
    if(y%2==1)
    {
        cout<<y<<" "<<x;
    }
    else
    {
        cout<<y<<" "<<n+1-x;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
