#include<bits/stdc++.h>
using namespace std;
int n,m,a[10100],b;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    b=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==b){
            if(i%n==0){
                if((i/n)%2==0) printf("%d %d",i/n,1);
                else printf("%d %d",i/n,n);
            }else{
                if((i/n+1)%2==0) printf("%d %d",i/n+1,n-(i%n)+1);
                else printf("%d %d",i/n+1,i%n);
            }
        }
    }
    return 0;
}
