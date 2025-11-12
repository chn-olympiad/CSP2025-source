#include<bits/stdc++.h>
using namespace std;

int n,m,sum,a[105];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int x=a[1];
    for(int i=0;i<=n*m;i++){
        for(int j=2;j<=n*m-i;j++){
            if(a[j]>a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            sum=i;
        }
    }
    int ans1;
    ans1=sum/n+1;
    int ans2;
    if(ans1%2==1){
        if(sum%n==0){
            ans2=n;
        }else{
            ans2=sum%n;
        }
    }else{
        if(sum%n==0){
            ans2=1;
        }else{
            ans2=n-sum%n+1;
        }
    }
    printf("%d %d",ans1,ans2);
    return 0;
}
