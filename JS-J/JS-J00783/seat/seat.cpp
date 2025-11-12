#include<bits/stdc++.h>
using namespace std;
int s[110];
void qs(int l,int r,int a[])
{
    int temp=a[l],i=l,j=r;
    if(i>=j)return;
    while(i<j)
    {
        while(a[j]>=temp)
        {
            j--;
            if(i==j)break;
        }
        a[i]=a[j];
            if(i==j)break;
        while(a[i]<=temp)
        {

            i++;
            if(i==j)break;
        }
        a[j]=a[i];
    }
    a[i]=temp;
    qs(l,i-1,a);
    qs(i+1,r,a);
    return;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,x,i,j,y;
    cin>>m>>n;
    for(i=1;i<=m*n;i++)
    {
            cin>>s[i];
    }
    x=s[1];
    qs(1,i,s);
    for(i=1;i<=m*n;i++)
    {

        if(s[i]==x)
        {
            j=i;
            break;
        }
    }
    y=j/m;
    if(j%m==0&&y%2==1)cout<<m<<" "<<y;
    if(j%m==0&&y%2==0)cout<<1<<" "<<y;
    if(j%m>0&&y%2==0)cout<<j%m<<" "<<y+1;
    if(j%m>0&&y%2==1)cout<<m-j%m+1<<" "<<y+1;
    return 0;
}
