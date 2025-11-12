#include<bits/stdc++.h>

using namespace std;

int n,m,score_r,sum1,location,c,r;
int s[101];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    sum1 = n * m;
    for(int i = 1;i <= sum1;i++){
        scanf("%d",&s[i]);
    }
    score_r=s[1];
    for(int i = 1;i <= sum1;i++){
        for(int j = 1;j <= sum1-i;j++){
            if(s[j] > s[j+1]){
                int t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
        if(s[sum1-i+1] == score_r){
            location = i;
            break;
        }
    }
    if(location%n == 0){
        c = location / n;
        if(c%2 == 0){
            r = 1;
        }
        else{
            r = n;
        }
    }
    else{
        c = location/n+1;
        if(c%2 == 0){
            r = n-location%n+1;
        }
        else{
            r = location%n;
        }
    }
    printf("%d %d",c,r);
    return 0;
}
