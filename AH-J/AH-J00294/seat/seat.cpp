//seat.cpp
#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N],x,k,tmp,n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    x=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--){
        tmp++;
        if(a[i]==x){
            k=(tmp%n==0)?tmp/n:tmp/n+1;
            tmp=(tmp%n==0)?n:tmp%n;
            if(k%2==0) printf("%d %d",k,m-tmp);
            else printf("%d %d",k,tmp);
            return 0;
        }
    }
    return 0;
}
