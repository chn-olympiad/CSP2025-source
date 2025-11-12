#include<bits/stdc++.h>
using namespace std;
int b[105],a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,j=1,k=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    x=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=n*m;i++){
        a[i]=b[m*n-i+1];
    }
    int g=1;
    while(1==1){
        if(k%2==1){
            for(j=1;j<=n;j++){
                if(a[g]==x){
                    cout<<k<<" ";
                    cout<<j;
                    return 0;
                }
                g++;
            }
            k++;
        }
        else{
            for(j=n;j>0;j--){
                if(a[g]==x){
                    cout<<k<<" ";
                    cout<<j;
                    return 0;
                }
                g++;
            }
            k++;
        }
    }
    return 0;
}
