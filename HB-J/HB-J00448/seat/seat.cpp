#include <iostream>
using namespace std;
int a[114],t[114],m,R,r;

void mbsort(int be,int en)
{
    if(be==en)
    {
        return;
    }
    int mid=(be+en)/2,i=be,k=be,j=mid+1;
    mbsort(be,mid);
    mbsort(mid+1,en);
    while(i<=mid&&j<=en)
    {
        if(a[i]>=a[j])
        {
            t[k]=a[i];
            i++;k++;
            continue;
        }
        if(a[i]<=a[j])
        {
            t[k]=a[j];
            j++;k++;
            continue;
        }
    }
    while(i<=mid)
    {
        t[k]=a[i];
        i++;k++;
    }
    while(j<=en)
    {
        t[k]=a[j];
        j++;k++;
    }
    for(int asd=be;asd<=en;asd++)
    {
        a[asd]=t[asd];
        if(a[asd]==R)
        {
            r=asd;
        }
    }
}

int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    R=a[1];
    mbsort(1,n*m);
    int mo=r%n,no=r/n;
    if(mo!=0)
    {
        no++;
    }
    if(mo==0)
    {
        mo=n;
    }
    if(no%2==1)
    {
        cout<<no<<" "<<mo;
    }
    else
    {
        cout<<no<<" "<<n+1-mo;
    }



    return 0;

}
