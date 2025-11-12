#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100009],cnt,x,y,sum;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%lld",a+i);
        if(i>=2&&a[i]>a[1])cnt++;
    }
    //cout<<cnt<<endl;
    if((cnt+1)%n!=0)x=(cnt+1)/n+1;
    else x=(cnt+1)/n;
    if(x%2==1){
        long long tmp=(cnt+1)%n;
        if(tmp){
            y=tmp;
        }
        else{
            y=n;
        }
    }
    else{
        long long tmp=(cnt+1)%n;
        if(tmp){
            y=n-(tmp-1);
        }
        else{
            y=1;
        }
    }
    printf("%lld %lld",x,y);
    return 0;
}
