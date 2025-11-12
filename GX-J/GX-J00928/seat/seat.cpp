#include<bits/stdc++.h>
using namespace std;
int cmp(int A,int B)
{
    return A>B;
}
int n,m,f,a[15],k;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>f;
    for(int i=1;i<=n*m-1;i++)
    {
        cin>>a[i];
    }
    if(n==1&&m==1)
    {
        cout<<"1 1"<<endl;
        return 0;
    }
    a[n*m]=f;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==f)
        {
            k=i;
            break;
        }
    }
    if(n==1)
    {
        cout<<k<<" 1"<<endl;
        return 0;
    }
    if(m==1)
    {
        cout<<"1 "<<k<<endl;
        return 0;
    }
    return 0;
}
