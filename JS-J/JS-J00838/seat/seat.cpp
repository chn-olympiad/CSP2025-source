#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,p,c,a[N*N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    p=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==p){
            p=i;
            break;
        }
    }
    for(int j=1;j<=m;j++){
        if(j&1){
            for(int i=1;i<=n;i++){
                c++;
                if(p==c){
                    printf("%d %d",j,i);
                    return 0;
                }
            }
        }
        else{
            for(int i=n;i>=1;i--){
                c++;
                if(p==c){
                    printf("%d %d",j,i);
                    return 0;
                }
            }
        }
    }
    return 0;
}
