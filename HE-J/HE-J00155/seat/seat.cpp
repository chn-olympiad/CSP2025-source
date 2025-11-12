#include<bits/stdc++.h>
using namespace std;
const int N=200;

int n,m;
int a[N][N];
bool cmp(int x,int y){
    return x>y;
}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int len=n*m;
    for(int i=1;i<=len;i++){
        cin>>a[i];
    }
    int r=a[1],k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m,j++){
            if(s[i][j]>s[i][j+2]){
                swap s[i][j+2];
            }
            if(s[i][j]==r){
                cout<<i<<" ";
            }
        }
    }
    int r=a[1],k;
    sort(a,a+len+1,cmp);
    int x;
    if(k*m==0)
    {
        x=k/2;
        cout<<x<<" ";
    }
    else{
        x=k/m+1;
        cout<<x<<" ";
    }
    return 0;
}
