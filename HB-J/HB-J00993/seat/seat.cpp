#include<bits/stdc++.h>
using namespace std;
long long n,m,x=1,y=1,q,p;
long long a[10001],b[10001][10001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    p=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        b[x][y]=a[i];
        if(x%2==0)
            q=1;
        else q=0;
        if(q==0){
            if(y==n&&x!=m)
                x++;
            else
                y++;
        }
       else if(q==1){
            if(y==0&&x!=0)
                x++;
            else
                y--;
       }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            if(p==b[i][j])
                cout<<j<<' '<<i;
    }
    return 0;
}
