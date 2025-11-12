#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[101]={0};
    int b[11][11]={0};
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int af=a[1];
    sort(a+1,a+1+n*m,cmp);
    int alen=1;
    for(int i=1;i<=m;i++)
    {
        if(i%2==0)
        {
            for(int j=n;j>=1;j--){
                b[j][i]=a[alen] ;
                alen++;
            }
        }
        else
        {
            for(int j=1;j<=n;j++){
                b[j][i]=a[alen];
                alen++;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(af==b[i][j])
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
