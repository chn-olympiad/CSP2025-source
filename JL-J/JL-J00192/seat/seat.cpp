#include<bits/stdc++.h>
using namespace std;
int b[400];
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    int i,j,k,n,m,h,l;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n*m;i++){
        scanf("%d",&b[i]);
    }
    k=b[1];
    sort(b+1,b+n*m+1);
    i=n*m;
    h=1,l=1;
    while(b[i]!=k){
        i--;
        if(l%2==1){
            if(h==n){
                l++;
            }
            else{
                h++;
            }
        }
        else{
            if(h==1){
                l++;
            }
            else{
                h--;
            }
        }
    }
    printf("%d %d\n",l,h);
    return 0;
}
