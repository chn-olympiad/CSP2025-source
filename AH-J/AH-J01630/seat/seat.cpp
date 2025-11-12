#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct node{
    int pricel,wu;
    friend bool operator <(const node a,const node b){
            return a.pricel>b.pricel;
    }
}a[10001];
int l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int o=n*m;
    for(int i=1;i<=o;i++)
    {
        cin>>a[i].pricel;
        a[i].wu=i;
    }
    sort(a+1,a+1+o);
    for(int i=1;i<=o;i++)
    {
        if(a[i].wu==1)
        {
            ans=i;
            break;
        }
    }
    if(ans%n==0)
        l=(int)ans/n;
    else
        l=(int)ans/n+1;
    if(l%2!=0)
    {
        if(ans%n==0)
        {
            cout<<l<<" "<<n;
            return 0;
        }
        else
        {
            cout<<l<<" "<<(int)(ans%n);
            return 0;
        }

    }
    else
    {
        if(ans%n==0)
        {
            cout<<l<<" "<<1;
            return 0;
        }
        else
        {
            cout<<l<<" "<<(int)(n-(ans%n)+1);
            return 0;
        }
    }
}
