#include<bits/stdc++.h>
using namespace std;
int a[500];
int b[10][10];
int main()
{
    int n,m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    int k=a[1];
    int s=0;
    for(int i=2;i<=n*m;i++)
        cin>>a[i];
        sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++)
    if(a[i]==k){
        s=i;
        break;
    }
    int l=0,i=1,j=1;
    s=n*m-s+1;
    while(l!=n*m)
    {
        l++;
        b[i][j]=l;
        if(l/m%2==0) i++;
        else i--;
        if(l%m==0&&l/m%2==0) {j++;
        i--;
        }
        if(l%m==0&&l/m%2==1){
            j++;
            i++;        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
    if(b[i][j]==s) {
        cout<<j<<" "<<i;
        break;
    }
        }
    }
    return 0;
}
