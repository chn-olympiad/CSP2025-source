#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("saet.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m],jishu=n*m-1;
    for(int i=0;i<n*m;i++)cin>>a[i];
    int a1=a[0];
    sort(a,a+n*m);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[jishu]==a1){
                    printf("%d %d",i,j);
                    return 0;
                }
                jishu--;
            }
        }
        else for(int j=n;j>=1;j++){
            if(a[jishu]==a1){
                printf("%d %d",i,j);
                return 0;
            }
            jishu--;
        }
    }
    return 0;
}
