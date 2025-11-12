#include<bits/stdc++.h>
using namespace std;
#define N 12   
int n,m,a[N*N],cnt;

int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int R=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==R)
        {
            R=n*m-i+1;
            break;
        }
    }
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
            for(int i=1;i<=n;i++)
                if(++cnt==R) cout<<j<<' '<<i;
        if(j%2==0)
            for(int i=n;i>=1;i--)
                if(++cnt==R) cout<<j<<' '<<i;
    }
    return 0;
}	
