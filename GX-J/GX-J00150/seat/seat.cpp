#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,a[105],cnt=1;
bool cmp(int x,int y){
    return x>y;
}
int t[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            cnt++;
        }
    }

    int s=a[1],xi=1,yi=1,c=1;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n+1;j++){
                t[j][i]=c;
                c++;
            }
        }else{
            for(int j=n;j>0;j--){
                t[j][i]=c-1;
                if(j!=n)c++;
                else ++c;
            }
            c--;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]==cnt){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }
    return 0;
}
