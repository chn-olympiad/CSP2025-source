#include<bits/stdc++.h>
using namespace std;
int n,m,t,cnt=1;
int a[15][15]={0};
int b[15][15]={0};
bool flag=true;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        if(i%2==1) {
            for(int j=1; j<=m; j++) {
                cin>>a[i][j];
            }
        } else {
            for(int j=m; j>=1; j--) {
                cin>>a[i][j];
            }
        }
    }
    t=100;
    while(t>=a[1][1]){
            flag=true;
        for(int i=1; i<=n; i++) {
            if(i%2==1) {
                for(int j=1; j<=m; j++) {
                    if(a[j][i]==t){
                            b[j][cnt/m+1]=t;
                        t--;
                        cnt++;
                        flag=false;
                    }
                }
            } else {
                for(int j=m; j>=1; j--) {
                    if(a[j][i]==t){
                            b[j][cnt/m+1]=t;
                        t--;
                        cnt++;
                        flag=false;
                    }
                }
            }
        }
        if(flag) {
            t--;
        }
    }
    for(int i=1; i<=n; i++) {
        if(i%2==1) {
            for(int j=1; j<=m; j++) {
                if(a[1][1]==b[j][i]) {
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        } else {
            for(int j=m; j>=1; j--) {
                if(a[1][1]==b[j][i]) {
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
    }
    return 0;
}

