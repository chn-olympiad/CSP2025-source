#include<bits/stdc++.h>
using namespace std;

const int KmaxN=11;

int a[KmaxN][KmaxN],n,m,a1[KmaxN*KmaxN],R,th;

bool comp(int x,int y){
    if(x<y){
        return true;
    }
    return false;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //ios:sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a1[i];
    }
    R=a1[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(a1[i]<a1[j]){
                th=a1[i];
                a1[i]=a1[j];
                a1[j]=th;
            }
        }
    }
    if(n==1){
        for(int j=1;j<=m;j++){
            if(a1[j]==R){
                cout<<j<<' '<<1<<endl;
                return 0;
            }
        }
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            if(a1[i]==R){
                cout<<1<<' '<<i<<endl;
                return 0;
            }
        }
    }
    th=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j%2==1){
                a[i][j]=a1[th];
                if(a1[th]==R){
                    cout<<"R="<<R<<' '<<th<<' '<<a[i][j]<<endl;
                    cout<<j<<' '<<i;
                    return 0;
                }
                th++;
            }
            else{
                a[i][m-j+1]=a1[th];
                if(a1[th]==R){
                        cout<<"R="<<R<<' '<<th<<' '<<a[i][m-j+1]<<endl;
                    cout<<j<<' '<<n-i+1;
                    return 0;
                }
                th++;
            }
        }
    }
    //cout<<a1[1]<<endl;

    //cout<<"R="<<R<<",a[2][1]="<<a[2][1]<<",a[2][2]="<<a[2][2]<<endl;

    /*for(int i=1;i<=n;i++){
        for(int j=1;i<=m;j++){
            if(a[i][j]==R){
                cout<<m-j+1<<' '<<n-i+1<<endl;
                return 0;
            }
            /*
            if(a[ii][jj]==R){
                cout<<jj<<' '<<ii<<endl;
                return 0;
            }*/

    return 0;
}
