#include<bits/stdc++.h>
using namespace std;
long long n,m,l;
int a[1010],b[1010][1010];
long long x=1,y=1;
int t=1,c=1;
bool cmp(long long q,long long h){
    return q>h;
}
int add(){
    t++;
    if(a[t]==l){
        return 1;
    }
    return 0;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    l=a[1];
    sort(a+1,a+m*n+1,cmp);
    b[x][y]=a[t++];
    for(int i=1;i<m;i++){
        while(x<n){
            x++;
            b[x][y]=a[t++];
        }
        if(m%2==1&&x==n&&y==m) break;
        y++;
        b[x][y]=a[t++];
        while(x>1){
            x--;
            b[x][y]=a[t++];
        }
        if(m%2==0&&x==1&&y==m) break;
        y++;
        b[x][y]=a[t++];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==l){
                cout<<j<<' '<<i<<endl;
            }
        }
    }
    return 0;
}
