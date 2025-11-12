#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,c[110],te,sumx,sumy,sum;
    cin>>a>>b;
    for(int i=1;i<=a*b;i++) cin>>c[i];
    te=c[1];
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=a*b;i++){
        if(c[i]==te){
            sum=i;
        }
    }
    sumx=sum/a+1;
    sumy=sum-sum/a*a;
    if(sumx%2==0){
        sumy=n+1-sumy;
    }
    cout<<sumx<<' '<<sumy;
    fclose(stdin);
    fclose(stdout)
    return 0;
}