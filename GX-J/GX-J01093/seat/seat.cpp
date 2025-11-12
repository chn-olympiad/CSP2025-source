#include <bits/stdc++.h>
using namespace std;
int s[1000][1000];
int a[1000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int b=n*m;
    int o;
    cin>>o;
    a[1]=o;//
    for(int i=2;i<=b-1;i++){
        cin>>a[i];
    }
    int g=1;
    sort(a+b+1,a+1);
    for(int i=1;i<=m;i++){
        if(m%2==1){
            for(int j=1;j<=n;j++){
                s[i][j]=a[g];
                g++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                s[i][j]=a[g];
                g++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j]==o){
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
