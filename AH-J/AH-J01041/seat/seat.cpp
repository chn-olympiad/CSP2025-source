#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],cnt,ans[15][15],tmp;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    tmp=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1)
            for(int i=1;i<=n;i++)
                ans[i][j]=a[++cnt];
        else
            for(int i=n;i>=1;i--)
                ans[i][j]=a[++cnt];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==tmp){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
