#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],a1[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1[1];
    int r=a1[1];
    for(int i=2;i<=n*m;i++)
        cin>>a1[i];
    sort(a1,a1+n*m+1);
    int x=0;
    for(int i=1;i<=n*m;i++)
        if(a1[i]==r){
            x=n*m+1-i;
            break;
        }
    int b=1,nm=1;
    while(b<=n*m){
        for(int i=1;i<=n;i++){
            a[i][nm]=b;
            b++;
        }
        nm+=1;
        for(int i=n;i>=1;i--){
            a[i][nm]=b;
            b++;
        }
        nm+=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==x){
                cout<<j<<" "<<i;
                return 0;
            }
    return 0;
}
