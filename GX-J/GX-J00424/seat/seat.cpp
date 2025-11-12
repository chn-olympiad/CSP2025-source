#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    int a1=m*n-1,s;
    for(int i=0;i<=n*m-1;i++){
        cin>>a[i];
    }
    s=a[0];
    sort(a+0,a+(m*n));

    int two[n][m];

    for(int i=0;i<=m-1;i++){
        for(int j=0;j<=n-1;j++){
            two[j][i]=a[a1];
            a1--;
        }
    }
    for(int i=0;i<=m-1;i++){
        for(int j=0;j<=n-1;j++){
            if(two[j][i]==s){
                if(i%2==1){
                    cout<<i+1<<" "<<(n+1)-(j+1);
                }
                else cout<<j+1<<" "<<i+1;
            }
        }
    }


    return 0;
}
