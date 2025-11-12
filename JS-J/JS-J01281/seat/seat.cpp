#include<bits/stdc++.h>
using namespace std;
int n,m,tot=0,a=1;
int score[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    memset(score,0,sizeof(score));
    scanf("%d%d",&n,&m);
    tot=n*m;
    for(int i=1;i<=tot;i++) scanf("%d",&score[i]);
    for(int i=2;i<=tot;i++){
        if(score[i]>score[1]){
            a++;
        }
    }
    int l1=(a-1)/(2*n);
    a-=l1*2*n;
    if(a<=n){
        printf("%d %d",l1*2+1,a);
    }
    else{
        printf("%d %d",l1*2+2,2*n+1-a);
    }
    return 0;
}
