#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000000][5];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--){
        int m=0,s=0,b=0,bj=0,ms=0,ss=0,bs=0;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
                int l=INT_MIN;
            for(int j=0;j<3;j++){
                if(j==1&&ms==n/2){
                    a[i][j]=0;
                }
                if(j==2&&ss==n/2){
                    a[i][j]=0;
                }
                if(j==3&&bs==n/2){
                    a[i][j]=0;
                }
                if(a[i][j]>l){
                    l=a[i][j];
                    bj=j;
                }
            }
            if(ms<=n/2&&bj==0){
                m+=a[i][bj];
                ms++;
            }
            if(ss<=n/2&&bj==1){
                s+=a[i][bj];
                ss++;
            }
            if(ms<=n/2&&bj==2){
                b+=a[i][bj];
                bs++;
            }
        }
        cout<<m+s+b;
    }

    return 0;
}

