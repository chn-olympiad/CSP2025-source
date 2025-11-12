#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    k=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[(i-1)*m+j]==k){
                if(i%2==1)
                    cout<<i<<' '<<j<<endl;
                else
                    cout<<i<<' '<<(n-j+1)<<endl;
                return 0;
            }
    return 0;
}
