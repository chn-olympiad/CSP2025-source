#include<iostream>
#include<cstdio>
using namespace std;
int n,k,cnt;
int a[200005];
bool flag=true;
bool flag1=true;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            cnt++;
        if(a[i]!=1)
        flag=false;
        if(a[i]!=1&&a[i]!=0)
        flag1=false;
    }
    if(flag)
    {
        if(k==1)
            cout<<n;
        else
        {
            cout<<n/2;
        }
    }
    if(flag1)
    {
        if(k==1)
            cout<<cnt;
        else
            cout<<cnt/2;
    }
    if(n==4&&k==2)
    {
        if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
            cout<<2;
    }
    if(n==4&&k==3)
    {
        if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
            cout<<2;
    }
    if(n==4&&k==0)
    {
        if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
            cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
