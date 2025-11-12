#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105],sorted[105],n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        sorted[i]=a[i];
    }
    for(int k=1;k<=n*m;k++){
        for(int l=1;l<=n*m-k;l++){
            if(sorted[l]<sorted[l+1])
              swap(sorted[l],sorted[l+1]);
    }
}
    int r_index,r,c;
    for(int i=1;i<=n*m;i++){
        if(a[1]==sorted[i]){
            r_index=i;
            if(r_index%n==0){
                c=r_index/n;
                if(c%2==0)
                  r=1;
                else
                  r=n;
            }
            else{
                c=r_index/n+1;
                if(c-1<1)
                   r=r_index%n;
                else{
                   if(c%2==1)
                     r=r_index%n;
                   else
                     r=n-r_index%n+1;
                }
            }
            break;
    }
}
    cout<<c<<" "<<r;
    return 0;
}
