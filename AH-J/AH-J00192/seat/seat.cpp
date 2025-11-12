#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10000],b[100][100];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }

    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=a[i];

        }
    }int x=b[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x==b[i][j]){
                if(i%2!=0){
                    cout<<i<<" "<<m-j;
                    return 0;
                }else{
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
