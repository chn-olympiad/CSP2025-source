#include<bits/stdc++.h>
using namespace std;
const int N=150;
const int M=15;
int n,m;
int a[N];
int b[M][M];
int c,r;//c->m,r->n
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int num=n*m;
    for(int i=1;i<=num;i++){
        cin>>a[i];
    }
    int res=a[1];
    sort(a+1,a+num+1,cmp);
    int nn=1,mm=1;
    for(int i=1;i<=num;i++){
        b[mm][nn]=a[i];
        if(mm%2==1&&nn<n){
            nn++;
        }
        else if(mm%2==0&&nn>1){
            nn--;
        }
        else if(nn=n&&mm%2==1&&mm<=m){
            mm++;
            nn=n;
        }
        else if(nn=1&&mm%2==0&&mm<=m){
            mm++;
            nn=1;

        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==res){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }



    return 0;
}
