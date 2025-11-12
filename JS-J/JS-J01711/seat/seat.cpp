#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int n , m , wei[1001][1001];
bool tmp(int a , int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d" , &n , &m);
    for(int i = 1;i<=n*m;i++)
        scanf("%d" , &a[i]);
    int R = a[1];
    sort(a+1,a+n*m+1,tmp);
    int xb;
    for(int i = 1;i<=n*m;i++)
        if(a[i]==R)
            xb = i;
    int x = 1,y = 1,now = 1;
    while(x<=n&&y<=m){
        if(now==xb){
            printf("%d %d" , y , x);
            return 0;
        }
        if(y%2!=0){
            if(x==n)
                y++;
            else
                x++;
        }else{
            if(x==1)
                y++;
            else
                x--;
        }
        now++;
    }
    printf("%d" , xb);
}
