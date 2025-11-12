#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,c,r,gr[105][105],a[1005];
bool cmp(int x,int y){
    return x>y;
}
bool flag=true;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int l=a[1];
    sort(a+1,a+n*m+1,cmp);
    int i=1,j=1;
    cout<<endl;
    for(int k=1;k<=n*m;k++){

        if(i==1&&k%n==0){
            gr[i][j]=a[k];
            flag=true;
            j++;
        }
        else if(i==n&&k%n==0){
            gr[i][j]=a[k];
            flag=false;
            j++;
        }
        if(flag){
            if(i==1&&k%n==0)continue;
            gr[i][j]=a[k];
            i++;
        }
        else{
            if(i==n&&k%n==0&&k!=n*m)continue;
            gr[i][j]=a[k];
            i--;
        }


    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(gr[i][j]==l){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }

    return 0;
}
