#include<bits/stdc++.h>
using namespace std;
int n,m,score[110],mine,x=1,z=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&score[i]);
    }
    mine=score[1];
    sort(score+1,score+1+n*m);
    for(int i=n*m;i>=1;i--){
        if(score[i]==mine) break;
        if(z%2){
            if(x==n) z++;
            else x++;
        }else{
            if(x==1) z++;
            else x--;
        }
    }
    printf("%d %d",z,x);
    return 0;
}
/*
模拟题 放洛谷上顶多标橙

MC服务器 mc.163mc.cn 来人
离线/盗版玩家可进
*/
