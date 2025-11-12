#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[105];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;++i){
        scanf("%d",&a[i]);
    }
    sort(a+2,a+n*m+1);
    int ans=0;
    for(int i=n*m;i>1;--i){
        ans++;
        if(a[i]<=a[1]){
            break;
        }
    }
    int ansm,ansn;
    if(ans%n==0){
        if((ans/n)%2==0){
            ansn=1;
            ansm=ans/n;
        }
        else{
            ansn=n;
            ansm=ans/n;
        }
    }
    else{
        if((((ans-(ans%n))/n)+1)%2==0){
            ansm=(ans-(ans%n))/n+1;
            ansn=n-(ans%n)+1;
        }
        else{
            ansm=(ans-(ans%n))/n+1;
            ansn=(ans%n);
        }
    }
    cout<<ansm<<" "<<ansn;
    return 0;
}
