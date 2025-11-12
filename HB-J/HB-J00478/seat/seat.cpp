#include<bits/stdc++.h>
using namespace std;
int a[110][110],b[10010];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l,R;
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=n*m;i++)
        cin>>b[i];
    R=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n;i++)
    {
        if(i%2==1){
            for(int j=1;j<=m;j++)
            {
                a[i][j]=b[l];
                l--;
            }

        }else{
            for(int j=m;j>=1;j--)
            {
                a[i][j]=b[l];
                l--;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==R){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
    return 0;
}

