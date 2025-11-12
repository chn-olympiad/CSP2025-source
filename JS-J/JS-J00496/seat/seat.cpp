#include <bits/stdc++.h>
using namespace std;

int n,m,s,t,x=1;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 1;i < n*m;i++){
        scanf("%d", &t);
        if(t > s){
            ++x;
        }
    }
    int ans1 = (x-1)/n+1;
    int ans2;
    if(ans1%2 == 0){
        ans2=n-((x-1)%n+1)+1;
    }else{
        ans2=(x-1)%n+1;
    }
    printf("%d %d",ans1,ans2);
    return 0;
}
