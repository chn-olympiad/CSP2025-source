#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[105],flag;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    flag=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=0;i--)
    {
        if(a[i]==flag)
        {
            if((n*m-i+1)%n==0)
            {
                if((n*m-i+1)/n%2==0) cout<<(n*m-i+1)/n<<" "<<1;
                else cout<<(n*m-i+1)/n<<" "<<n;
            }
            else
            {
                if(((n*m-i+1)/n+1)%2==0) cout<<(n*m-i+1)/n+1<<" "<<n-(n*m-i+1)%n+1;
                else cout<<(n*m-i+1)/n+1<<" "<<(n*m-i+1)%n;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
