#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt,p,ans1=1,ans2=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i=-~i) scanf("%d",&a[i]);
    cnt=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i=-~i){
        if(a[i]==cnt){
            p=i-1;
            break;
        }
    }
    while(p){
        if(ans1&1){
            if(ans2==n) ans1++;
            else ans2++;
        }
        else{
            if(ans2==1) ans1++;
            else ans2--;
        }
        p--;
    }
    printf("%d %d",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
