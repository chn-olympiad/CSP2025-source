#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat[11][11];
int a[101];
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int sum=n*m;
    for(int i=1;i<=sum;i++)cin>>a[i];
    int ans=a[1];
    sort(a+1,a+sum+1,cmp);
    int cnt;
    for(int i=1;i<=sum;i++){
        if(a[i]==ans){
            cnt=i;
            break;
        }
    }
    int x=1,y=1,flag=0;
    for(int i=1;i<=sum;i++)
    {
        seat[x][y]=a[i];
        if(flag==0){
            x++;
        }else{
            x--;
        }
        if(x>n){
            flag=1;
            y++;
            x--;
        }
        if(x<1){
            flag=0;
            y++;
            x++;
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(seat[i][j]==a[cnt]){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
}
