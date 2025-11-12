#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d,x=1,y=1,s[10010];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&a,&b);
    c=a*b;
    for(int i=0;i<c;i++){
        scanf("%lld",&s[i]);
    }
    d=s[0];
    sort(s+0,s+c);
    for(int i=c-1;i>=0;i--){
        //printf("%lld %lld\n",y,x);
        if(s[i]==d){
            printf("%lld %lld",y,x);
            return 0;
        }
        if(y%2==1)x++;
        else x--;
        if(x>a)y++,x=a;
        else if(x<1)x=1,y++;
    }
    return 0;
}
