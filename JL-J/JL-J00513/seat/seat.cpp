#include <bits/stdc++.h>
using namespace std;
int a[105],i,j,n,m,b,c,x;
int w(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
     cin>>n>>m;
     b=0;
     for(i=0;i<n*m;i++){
        cin>>a[i];
     }x=a[0];
     sort(a,a+n*m,w);
     for(i=1;i<=m;i++){
        if(i%2==1){
            for(j=1;j<=n;j++){
                if(a[b++]==x){
                    cout<<i<<" "<<j;
                    i=m+2;
                    break;
                }
            }
        }else{
            for(j=n;j>=1;j--){
                if(a[b++]==x){
                    cout<<i<<" "<<j;
                    i=m+2;
                    break;
                }
            }
        }
     }
    return 0;
}

