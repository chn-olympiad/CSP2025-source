
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[100];
    int n,m,rp;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            rp=n*m-i+1;
        }
    }
    if(rp<=n)
    {
        cout<<1<<" "<<rp;
    }
    else
    {
        int h,l;
        if(rp%n==0)
        {
            if((rp/n)%2==0){cout<<h/n<<" "<<1;}
            else {cout<<h/n<<" "<<n;}
        }
        else{
            int yu=rp-(rp/n)*n;
            if((rp/n+1)%2==0){
                cout<<rp/n+1<<" "<<n-yu+1;
         }
         else{
            cout<<rp/n+1<<" "<<yu;
         }
        }
    }
    return 0;
}
