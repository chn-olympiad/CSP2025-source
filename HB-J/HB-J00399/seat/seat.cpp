#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int s[15][15];
int zz;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    zz=a[1];
    for(int i=1;i<=n*m-1;i++){
        for(int j=1;j<=n*m-i;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }
    int xb=0;
    for(int i=1;xb<n*m;){
        for(int j=1;xb<n*m;){
                //cout<<i<<" "<<j<<endl;
            xb++;
            s[i][j]=a[xb];
            if(j%2==1&&i!=n){
                i++;
            }
            else if(j%2==1&&i==n){
                i=n,j++;
            }
            else if(j%2==0&&i!=1){
                i--;
            }
            else if(j%2==0&&i==1){
                i=1;j++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
                //cout<<s[i][j]<<" ";
            if(s[i][j]==zz){
                cout<<j<<" "<<i<<endl;
                return 0;
            }
        }
        //cout<<endl;
    }
    return 0;
}
