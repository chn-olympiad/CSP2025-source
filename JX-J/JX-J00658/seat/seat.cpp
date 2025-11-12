#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,c;
    scanf("%d %d",&n,&m);
    int a[n*m+1];
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        if(i==1)c=a[i];
    }for(int i=1;i<=n*m;i++){
        for(int j=1;j<+n*m;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
        }
    }for(int i=1;i<=n*m;i++){
        if(c==a[i]){
            if(i%n==0){
                if(i/n%2==0)cout<<i/n<<' '<<1;
                else cout<<i/n<<' '<<n;
            }
            else {
                if((i/n+1)%2==0)cout<<i/n+1<<' '<<n-i%n+1;
                else cout<<i/n+1<<' '<<i%n;
            }
        }

    }
    return 0;
}
