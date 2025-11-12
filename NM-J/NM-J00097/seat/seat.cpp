#include<bits/stdc++.h>
using namespace std;
int n,m,z;
int a[50005];
int s[50005][50005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        z=a[1];
    }
    sort(a+1,a+m*n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n*m;k++)
            {
                a[k]=s[i][j];
                if(a[k]==z){
                    cout<<i<<' '<<j;
                }
            }
        }
    }

}
