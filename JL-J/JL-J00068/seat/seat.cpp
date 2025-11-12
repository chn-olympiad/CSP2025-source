#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,k,s=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+m*n+1);
    for(int i=m*n;i>=1;i--)
    {
        s++;
        if(a[i]==k)
        {
            break;
        }
    }
    if(s%(2*n)>n)
    {
        cout<<s/n+1<<' '<<n-(s%n)+1;
    }
    else if(s%(2*n)<n&&s%(2*n)>0)
    {
        cout<<s/n+1<<' '<<s%n;
    }
    else if(s%(2*n)==n||s%(2*n)==0)
    {
        cout<<s/n<<' '<<n;
    }
}
