#include<bits/stdc++.h>
using namespace std;
int n,m;
int As;
int Ar;
int a[205];
bool cmp(int x,int y)
{
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    As=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==As)
        {
            Ar=i;
            break;
        }
    }
    if(Ar%n==0)
    {
        cout<<Ar/n<<" ";
        if(Ar/n%2==0)
        {
            cout<<1;
        }
        else
        {
            cout<<n;
        }
    }
    else
    {
        cout<<Ar/n+1<<" ";
        if((Ar/n+1)%2==0)
        {
            cout<<n-Ar%n+1;
        }
        else
        {
            cout<<Ar%n;
        }
    }

    return 0;
}
