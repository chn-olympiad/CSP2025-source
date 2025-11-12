#include<bits/stdc++.h>
using namespace std;
long long a[20][20];
long long b[110];
long long n,m,xa,cnt=1;
bool cmp(int x,int y){
    return x>y;
}
void js(int x)
{
    for(int i=1;i<=n;i++){
        a[i][x]=b[cnt];
        cnt++;
    }
}
void os(int x)
{
    for(int i=n;i>=1;i--){
        a[i][x]=b[cnt];
        cnt++;
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    xa=b[1];
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1) js(i);
        else os(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==xa){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
}
