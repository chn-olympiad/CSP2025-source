#include <bits/stdc++.h>
using namespace std;
int x[10000000][3];
void a(int n){
    int m=0;
    int c[3]={0,0,0};
    for (int i=0;i<=n;i++){
        for (int j=0;j<=2;j++){
            cin>>x[i][j];
        }
    }
    int max=0;
    while(true){
            int z=1;
        for (int i=n;i>=0;i--){
            for (int j=0;j<=2;j++){
                m=m+x[i][j];
                c[i]++;
            }
            int p=0;
            for (int j=0;i<=2;j++){
                if (c[i]<=n/2){
                    p++;
                }
            }
            if (m>=max and p==3){
                max=m;
            }
        }
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    for (int i=0;i<=t;i++){
        int n;
        int p=0;
        cin>>n;
        a(n);
    }
    return 0;
}
