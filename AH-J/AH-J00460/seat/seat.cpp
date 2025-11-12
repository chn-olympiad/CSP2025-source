#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    std::cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        std::cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int t=1;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                b[i][j]=a[t];
                if(b[i][j]==x){
                    std::cout<<i<<" "<<j;
                    return 0;
                }
                t++;
            }
        }else{
            for(int i=n;i>=1;i--){
                b[i][j]=a[t];
                if(b[i][j]==x){
                    std::cout<<i<<" "<<j;
                    return 0;
                }
                t++;
            }

        }
    }
    return 0;
}
