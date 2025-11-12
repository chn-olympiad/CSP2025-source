#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[104];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+1+(n*m));
    int cnt=0;
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==r)
        {
            cnt=abs(i-n*m-1);
            break;
        }
    }
    if(cnt%n!=0)
    {
        cout<<cnt/n+1<<" ";
        if((cnt/n+1)%2==0){
            cout<<n-(cnt%n)+1;
        }
        else {
            cout<<cnt%n;
        }

    }
    else
    {
        cout<<cnt/n<<" ";
        if((cnt/n)%2==0)
        {
            cout<<1;
        }
        else{
            cout<<n;
        }
    }
    return 0;
}
