#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[120],b[20][20];
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c=0,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)r=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                c++;
                b[j][i]=a[c];
            }
        }
        else{
            for(int j=n;j>=1;j--){
                c++;
                b[j][i]=a[c];
            }
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(b[i][j]==r){
                cout<<j<<" "<<i;
                return 0;
           }

        }
    }
return 0;}
