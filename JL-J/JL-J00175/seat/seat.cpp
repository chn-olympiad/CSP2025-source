#include <bits/stdc++.h>
using namespace std;
int a[100],s[11][11],i,j,n,m,t,cnt;
bool cmp(int x,int y){
    return (x>y);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n*m;i++){
        cin>>a[i];
    }
    t=a[0];
    sort(a,a+n*m,cmp);
    for(i=0;i<m;i++){
        bool flag=0;
        for(j=0;j<n;j++){
            s[i][j]=a[cnt];
            if(s[i][j]==t){
                flag=1;
                break;
            }
            cnt++;
        }
        if(flag)break;
        if(++i==m) break;
        for(j=n-1;j>-1;j--){
            s[i][j]=a[cnt];
            if(s[i][j]==t){
                flag=1;
                break;
            }
            cnt++;
        }
        if(flag)break;
    }
    cout<<i+1<<" "<<j+1;
    return 0;
}
