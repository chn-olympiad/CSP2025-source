#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[250];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int phz=0;
    cin>>phz;
    a[0]=phz;
    for(int i=1;i<n*m;i++)
    {
        cin>>a[i];
    }
    int xx=n*m;
    sort(a,a+xx,cmp);
    int ans=0;
    for(int i=0;i<n*m;i++)
    {
        if(a[i]==phz)
        {
            ans=i+1;
            break;
        }
    }
    if(((ans%n==0&&(ans/n)%2==1))|| (ans%n!=0&&((ans/n)+1)%2==1))//jishulie
    {
        if(ans%n==0)
        {
            cout<<ans/n<<" "<<n;
            return 0;
        }
        else{
            cout<<(ans/n)+1<<" "<<ans%n;
            return 0;
        }
    }
    if((ans%n==0&&(ans/n)%2==0)||(ans%n!=0&&((ans/n)+1)%2==0))//oushulie
    {
        if(ans%n==0)
        {
            cout<<ans/n<<" "<<1;
            return 0;
        }
        else{
            if(n%2==1)
            {
                if(ans%n==(n/2)+1)
                {
                    cout<<(ans/n)+1<<" "<<(n/2)+1;
                    return 0;
                }
                else{
                    cout<<(ans/n)+1<<" "<<n-(ans%n)+1;
                    return 0;
                }
            }
            else{
                if(ans%n==1)
                {
                    cout<<(ans/n)+1<<" "<<n;
                }
                else{
                    cout<<(ans/n)+1<<" "<<n-(ans%n)+1;
                }
            }
        }
    }
    return 0;
}
