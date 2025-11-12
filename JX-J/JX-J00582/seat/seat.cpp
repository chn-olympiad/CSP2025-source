#include <bits/stdc++.h>
using namespace std;
int s[105];
bool gcd(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&s[i]);
    }
    int t=s[1];
    sort(s+1,s+m*n+1,gcd);
    int c=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(s[c]==t){
                if(i%2){
                    printf("%d %d",i,j+1);
                    return 0;
                }
                else{
                    printf("%d %d",i,m-j);
                    return 0;
                }

            }
            c++;
        }
    }
    return 0;
}
