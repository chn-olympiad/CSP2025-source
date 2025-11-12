#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l=1,r;
    cin>>n>>m;
    int f2[105][105];
    int f1[10000];
    for(int i=1;i<=n*m;i++){
        cin>>f1[i];
    }
    r=f1[1];
    sort(f1+1,f1+n*m+1);
    for(int i=m;i>=1;i--){
        if(i%2==0){
            for(int j=1;j<=n;j++){
                f2[i][j]=f1[l];
                l++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                f2[i][j]=f1[l];
                l++;
            }
        }
    }

    for(int i=m;i>=1;i--)
        for(int j=n;j>=1;j--){
            if(f2[i][j]==r){
                cout<<i<<" "<<j;
            }
        }

    return 0;
}
