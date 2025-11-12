#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[200];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)cin >>b[i];
    int xx=b[1];
    sort(b+1,b+1+n*m,cmp);
    int p=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                a[j][i]=b[++p];
                if(b[p]==xx){
                    cout << i<<' '<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                a[j][i]=b[++p];
                if(b[p]==xx){
                    cout << i<<' '<<j;
                    return 0;
                }
            }
        }

    }

    return 0;
}
